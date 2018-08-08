/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_hex_precision_width_handler.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 21:15:25 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/08 18:20:44 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/libftprintf.h"

void	ft_format_hex_precision_width_handler(t_data *elem)
{
	int		len;
	int		i;
	int		range;
	char	*str;
	char	*buf;

	len = ft_strlen(elem->buffer);
	i = 0;
	if (elem->width > len)
	{
		str = ft_strnew(elem->width - len);
		range = elem->width - len;
		while (range--)
			str[i++] = ' ';
		buf = elem->buffer;
		elem->buffer = ft_strjoin(str, buf);
		free(buf);
		free(str);
	}
}
