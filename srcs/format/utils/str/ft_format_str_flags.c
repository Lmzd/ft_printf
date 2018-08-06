/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_str_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 16:43:13 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/06 07:52:25 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/ft_printf.h"

void	ft_format_str_flags(t_data *elem)
{
	if (!elem->flags.dash
		|| (elem->flags.dash && (elem->width < (int)ft_strlen(elem->buffer))))
	{
		if (elem->precision > -1)
		{
			ft_format_str_precision_handler(elem);
			ft_format_str_width_handler(elem);
		}
		else
			ft_format_str_width_handler(elem);
	}
	else
	{
		if (elem->precision > -1)
		{
			ft_format_str_precision_handler(elem);
			ft_format_str_moins_flag_handler(elem);
		}
		else
			ft_format_str_moins_flag_handler(elem);
	}
}
