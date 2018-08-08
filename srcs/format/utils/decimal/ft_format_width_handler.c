/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_width_handler.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 08:33:29 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/07 07:04:35 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/libftprintf.h"

void	ft_format_no_width_handler(t_data *elem)
{
	char	*buf;

	if (elem->neg)
	{
		buf = elem->buffer;
		elem->buffer = ft_strjoin("-", buf);
		free(buf);
	}
}

void	ft_format_width_neg_helper(t_data *elem, char *str)
{
	int		index;
	char	*buf;

	if (elem->flags.zero)
	{
		str[0] = '-';
		free(elem->buffer);
		elem->buffer = str;
	}
	else
	{
		index = 0;
		while (str[index] < '0' || str[index] > '9')
			index++;
		free(elem->buffer);
		buf = ft_strreplace(str, '-', --index);
		elem->buffer = buf;
		return ;
	}
}

void	ft_format_width_helper(t_data *elem,
	int width, int len, char extension)
{
	char	*str;

	str = ft_strnew(width + elem->neg + 1);
	while (len--)
		str[--width] = elem->buffer[len];
	while (width--)
		str[width] = extension;
	if (elem->neg)
	{
		ft_format_width_neg_helper(elem, str);
		return ;
	}
	else if (elem->null && (elem->type == 'c' || elem->type == 'C'))
		str[ft_strlen(str) - 1] = 0;
	free(elem->buffer);
	elem->buffer = str;
}

void	ft_format_width_handler(t_data *elem)
{
	int		len;
	int		width;
	char	extension;

	len = ft_strlen(elem->buffer);
	width = elem->width;
	if (width <= len)
	{
		ft_format_no_width_handler(elem);
		return ;
	}
	extension = ' ';
	if (width > len)
	{
		if (elem->flags.zero)
			extension = '0';
	}
	else
		return ;
	ft_format_width_helper(elem, width, len, extension);
}
