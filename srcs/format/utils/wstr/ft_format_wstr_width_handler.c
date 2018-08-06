/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_wstr_width_handler.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 17:12:55 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/06 07:27:03 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/ft_printf.h"

void	ft_format_wstr_width_handler(t_data *elem)
{
	int		len;
	int		range;
	int		width;
	wchar_t	prefix;
	wchar_t	*str;

	len = ft_strwlen(elem->wbuffer);
	width = elem->width;
	prefix = (elem->flags.zero) ? L'0' : L' ';
	if (width <= len)
		return ;
	range = width - len;
	if (!(str = (wchar_t*)malloc(sizeof(wchar_t) * width + 1)))
		return ;
	while (len--)
		str[--width] = elem->wbuffer[len];
	while (width--)
		str[width] = prefix;
	if (elem->wmalloc)
		free(elem->wbuffer);
	elem->wbuffer = str;
	elem->wmalloc = 1;
}
