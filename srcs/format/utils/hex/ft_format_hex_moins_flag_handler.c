/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_hex_moins_flag_handler.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 21:23:08 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/12 06:21:02 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/libftprintf.h"

void	ft_format_hex_hash(t_data *elem)
{
	char	*prefix;
	char	*buf;

	prefix = (elem->type == 'O' || elem->type == 'o')
		? ft_strdup(OCT_PREFIX) : ft_strdup(HEX_PREFIX);
	buf = elem->buffer;
	elem->buffer = ft_strjoin(prefix, buf);
	free(buf);
	free(prefix);
}

void	ft_format_hex_moins_flag_handler(t_data *elem)
{
	int		len;
	int		width;
	int		range;
	char	*str;
	char	*buf;

	width = elem->width;
	if (elem->flags.hash || elem->type == 'p')
		ft_format_hex_hash(elem);
	len = ft_strlen(elem->buffer);
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
