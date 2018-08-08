/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_wstr_flags.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 16:46:17 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/07 07:04:35 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/libftprintf.h"

void	ft_format_wstr_flags(t_data *elem)
{
	if (!elem->flags.dash
		|| (elem->flags.dash && (elem->width < (int)ft_strlen(elem->buffer))))
	{
		if (elem->precision > -1)
		{
			ft_format_wstr_precision_handler(elem);
			ft_format_wstr_width_handler(elem);
		}
		else
			ft_format_wstr_width_handler(elem);
	}
	else
	{
		if (elem->precision > -1)
		{
			ft_format_wstr_precision_handler(elem);
			ft_format_wstr_moins_flag_handler(elem);
		}
		else
			ft_format_wstr_moins_flag_handler(elem);
	}
}
