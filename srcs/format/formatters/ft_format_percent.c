/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 03:37:52 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/21 17:48:44 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libftprintf.h"

void	ft_format_percent(t_data *elem, va_list ap)
{
	(void)ap;
	elem->buffer = ft_strdup("%");
	elem->wmalloc = 1;
	ft_format_str_flags(elem);
	if (!elem->precision && elem->width == -1)
	{
		free(elem->buffer);
		elem->buffer = ft_strdup("%");
	}
	else if (!elem->precision && !elem->flags.dash
		&& elem->width == ft_strlen(elem->buffer))
		ft_strreplace(elem->buffer, '%', ft_strlen(elem->buffer) - 1);
}
