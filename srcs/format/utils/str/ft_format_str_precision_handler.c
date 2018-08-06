/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_str_precision_handler.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 17:11:45 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/06 07:00:04 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/ft_printf.h"

void	ft_format_str_precision_handler(t_data *elem)
{
	int		len;
	int		preci;
	char	*buf;

	buf = ft_strdup(elem->buffer);
	len = ft_strlen(buf);
	preci = elem->precision;
	if (elem->precision <= len)
		buf[preci] = '\0';
	if (elem->wmalloc)
		free(elem->buffer);
	elem->buffer = buf;
	elem->wmalloc = 1;
}
