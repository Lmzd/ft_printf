/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_null_value.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 23:13:40 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/08 12:51:20 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/libftprintf.h"

void	ft_format_null_value(t_data *elem)
{
	int		len;
	char	*buf;

	if (elem->null)
	{
		len = ft_strlen(elem->buffer);
		if (!elem->precision && elem->width >= 1)
		{
			buf = ft_strreplace(elem->buffer, ' ', len - 1);
			free(elem->buffer);
			elem->buffer = buf;
		}
		if (!elem->precision && elem->width == -1 && elem->flags.spaces)
		{
			free(elem->buffer);
			elem->buffer = ft_strdup(" ");
		}
		else if (!elem->precision && elem->width == -1 && elem->flags.plus)
		{
			free(elem->buffer);
			elem->buffer = ft_strdup("+");
		}
		else if (!elem->precision && elem->width == -1)
		{
			free(elem->buffer);
			elem->buffer = "";
		}
	}
}
