/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_precision_moins_flag_handler.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 19:40:52 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/04 23:17:53 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/ft_printf.h"

void	ft_format_precision_moins_flag_handler_helper(t_data *elem, char *str)
{
	char *res;

	if (elem->neg)
	{
		res = ft_strjoin(elem->buffer, str);
		free(elem->buffer);
		elem->buffer = ft_strjoin("-", res);
		free(res);
	}
}

void	ft_format_precision_moins_flag_handler(t_data *elem)
{
	int		len;
	int		width;
	int		range;
	char	*str;

	len = ft_strlen(elem->buffer);
	width = elem->width;
	if (width < len)
		return ;
	str = ft_strnew(width - len);
	range = width - len;
	while (range--)
		str[range] = ' ';
	ft_format_precision_moins_flag_handler_helper(elem, str);
	free(str);
}
