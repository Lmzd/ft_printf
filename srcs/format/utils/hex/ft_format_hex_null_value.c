/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_hex_null_value.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 15:07:45 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/07 02:40:16 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/ft_printf.h"

void		ft_format_hex_null_value_helper(t_data *elem)
{
	if (!elem->precision && elem->type == 'p' && elem->width == -1)
	{
		free(elem->buffer);
		elem->buffer = ft_strdup("0x");
	}
	if (!elem->precision && elem->flags.hash
		&& (elem->type == 'o' || elem->type == 'O') && elem->width == -1)
	{
		free(elem->buffer);
		elem->buffer = ft_strdup("0");
	}
	else if (!elem->precision && !elem->flags.hash
		&& (elem->type == 'o' || elem->type == 'O') && elem->width == -1)
	{
		free(elem->buffer);
		elem->buffer = ft_strdup("");
	}
}

void		ft_format_hex_null_value(t_data *elem)
{
	int		len;
	char	*buf;

	if (elem->null)
	{
		len = ft_strlen(elem->buffer);
		if (!elem->precision && !elem->flags.dash
			&& elem->width >= 1 && elem->type != 'p')
		{
			buf = elem->buffer;
			elem->buffer = ft_strreplace(buf, ' ', len - 1);
			free(buf);
		}
		if (!elem->precision && elem->flags.dash
			&& elem->width >= 1 && elem->type != 'p')
			elem->buffer[0] = ' ';
		ft_format_hex_null_value_helper(elem);
	}
}