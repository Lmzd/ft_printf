/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_precision_moins_flag_handler.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 19:40:52 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/08 07:21:23 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/libftprintf.h"

void	ft_format_precision_moins_flag_handler_helper(t_data *elem, char *str)
{
	char *res;

	res = ft_strjoin(elem->buffer, str);
	free(elem->buffer);
	if (elem->neg)
	{
		elem->buffer = ft_strjoin("-", res);
		free(res);
	}
	else
		elem->buffer = res;

}

void	ft_format_precision_moins_flag_handler(t_data *elem)
{
	int		len;
	int		range;
	char	*str;

	len = ft_strlen(elem->buffer);
	if (elem->width < len)
		return ;
	range = elem->width - len;
	str = ft_strnew(range);
	while (range--)
		str[range] = ' ';
	ft_format_precision_moins_flag_handler_helper(elem, str);
	free(str);
}
