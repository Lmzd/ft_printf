/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 03:37:52 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/06 09:35:21 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

void	ft_format_percent(t_data *elem, va_list ap)
{
	(void)ap;
	elem->buffer = ft_strdup("%");
	elem->wmalloc = 1;
	ft_format_str_flags(elem);
}