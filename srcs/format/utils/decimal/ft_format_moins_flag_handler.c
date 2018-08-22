/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_moins_flag_handler.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 17:07:37 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/21 19:56:02 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/libftprintf.h"

void	ft_format_moins_flag_handler_no_width(t_data *elem)
{
	char	*buf;

	if (elem->neg)
	{
		buf = elem->buffer;
		elem->buffer = ft_strjoin("-", buf);
		free(buf);
	}
}

void	ft_format_moins_flag_helper(t_data *elem, int len)
{
	char	*str;
	char	*buf;
	char	*res;

	res = NULL;
	str = ft_fillit(' ', elem->width - len - elem->neg);
	if (elem->null && (elem->type == 'c' || elem->type == 'C'))
		str[ft_strlen(str) - 1] = 0;
	buf = elem->buffer;
	if (str)
	{
		res = ft_strjoin(buf, str);
		free(str);
	}
	if (elem->neg)
	{
		elem->buffer = (res) ? ft_strjoin("-", res) : ft_strjoin("-", buf);
		free(res);
	}
	else
		elem->buffer = res;
	free(buf);
}

void	ft_format_moins_flag_handler(t_data *elem)
{
	int		len;
	int		width;

	width = elem->width;
	len = (elem->type == 'C' || (elem->type == 'c' && elem->modifier.l))
			? ft_wcharlen(elem->value)
			: ft_strlen(elem->buffer);
	if (width <= len || !elem->flags.dash)
		ft_format_moins_flag_handler_no_width(elem);
	else
		ft_format_moins_flag_helper(elem, len);
}
