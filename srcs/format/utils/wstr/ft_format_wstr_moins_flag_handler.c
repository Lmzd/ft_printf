/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_wstr_moins_flag_handler.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 17:34:59 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/06 07:59:47 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/ft_printf.h"

void	ft_format_wstr_moins_flag_handler(t_data *elem)
{
	int		len;
	int		width;
	int		range;
	char	*gap;

	len = ft_strwlen(elem->wbuffer);
	width = elem->width;
	if (width <= len)
		return ;
	range = width - len;
	gap = ft_fillit(' ', range);
	elem->buffer = gap;
}
