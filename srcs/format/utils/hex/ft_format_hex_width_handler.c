/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_hex_width_handler.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 21:06:21 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/07 07:04:35 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/libftprintf.h"

void	ft_format_hex_width_helper(t_data *elem, char *prefix,
	char *str, int width)
{
	int		is_octal;
	int		len;
	char	*buf;

	len = ft_strlen(elem->buffer);
	is_octal = (elem->type == 'O' || elem->type == 'o') ? 1 : 0;
	if (width < len + 2)
	{
		buf = elem->buffer;
		elem->buffer = ft_strjoin(prefix, buf);
		free(buf);
	}
	else
	{
		while (len--)
			str[--width] = elem->buffer[len];
		if (!is_octal)
			str[--width] = 'x';
		str[--width] = '0';
		if (width > 0)
			while (width--)
				str[width] = ' ';
		free(elem->buffer);
		elem->buffer = ft_strdup(str);
	}
}

void	ft_format_hex_width_pointer(t_data *elem, int width, char *str)
{
	int len;

	len = ft_strlen(elem->buffer);
	while (len--)
		str[--width] = elem->buffer[len];
	while (width--)
		str[width] = ' ';
	free(elem->buffer);
	elem->buffer = ft_strdup(str);
}

void	ft_format_hex_width_with_len(t_data *elem, char *prefix)
{
	char	*str;

	if (elem->flags.hash || elem->type == 'p')
	{
		str = elem->buffer;
		elem->buffer = ft_strjoin(prefix, str);
		free(str);
	}
	ft_strdel(&prefix);
}

void	ft_format_hex_width_handler(t_data *elem)
{
	int		len;
	int		range;
	char	*str;
	char	*prefix;

	prefix = (elem->type == 'o' || elem->type == 'O')
		? ft_strdup("0") : ft_strdup("0x");
	len = ft_strlen(elem->buffer);
	if (elem->width <= len)
	{
		ft_format_hex_width_with_len(elem, prefix);
		return ;
	}
	range = elem->width - len;
	str = ft_strnew(elem->width);
	if (elem->flags.zero)
		ft_format_hex_width_zero_flag(elem, prefix, str, elem->width);
	else if (!elem->flags.hash && elem->type != 'p')
		ft_format_hex_width_pointer(elem, elem->width, str);
	else
		ft_format_hex_width_helper(elem, prefix, str, elem->width);
	ft_strdel(&prefix);
	ft_strdel(&str);
}
