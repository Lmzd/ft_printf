/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_str_width_handler.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 17:12:55 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/06 05:11:56 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/ft_printf.h"

void	ft_format_str_width_handler(t_data *elem)
{
	int		len;
	int		range;
	char	prefix;
	char	*str;
	char	*buf;

	len = ft_strlen(elem->buffer);
	if (elem->width <= len)
		return ;
	prefix = (elem->flags.zero) ? '0' : ' ';
	range = elem->width - len;
	str = ft_fillit(prefix, range);
	buf = elem->buffer;
	elem->buffer = ft_strjoin(str, buf);
	free(str);
	if (elem->type == 'S' || elem->wmalloc)
		free(buf);
	elem->wmalloc = 1;
}
