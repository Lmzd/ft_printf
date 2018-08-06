/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_precision_handler.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:28:40 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/06 07:50:58 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/ft_printf.h"

void	ft_format_precision_handler_helper(t_data *elem, char *str)
{
	char *res;

	if (elem->flags.plus)
		res = ft_strjoin("+", str);
	else
		res = ft_strjoin(" ", str);
	elem->buffer = res;
	free(str);
}

void	ft_format_precision_handler(t_data *elem)
{
	int		len;
	int		preci;
	char	*str;
	char	extension;

	len = ft_strlen(elem->buffer);
	preci = elem->precision;
	if (preci <= len)
		return ;
	extension = '0';
	str = ft_strnew(preci);
	while (len--)
		str[--preci] = elem->buffer[len];
	while (preci--)
		str[preci] = extension;
	free(elem->buffer);
	if (((elem->type != 'u') && (elem->type != 'U'))
		&& (elem->flags.plus || elem->flags.spaces) && !elem->neg)
		ft_format_precision_handler_helper(elem, str);
	else
		elem->buffer = str;
}
