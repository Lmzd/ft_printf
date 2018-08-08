/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_hex_precision_moins_flag_handler.        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 21:14:53 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/07 07:04:35 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/libftprintf.h"

void	ft_format_hex_precision_moins_flag_handler(t_data *elem)
{
	int		len;
	int		width;
	int		range;
	char	*str;
	char	*buf;

	len = ft_strlen(elem->buffer);
	width = elem->width;
	if (width <= len)
		return ;
	range = width - len;
	str = ft_strnew(range);
	while (range--)
		str[range] = ' ';
	buf = elem->buffer;
	elem->buffer = ft_strjoin(buf, str);
	free(buf);
	free(str);
}
