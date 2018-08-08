/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_str_moins_flag_handler.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 17:34:59 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/07 07:04:35 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/libftprintf.h"

void	ft_format_str_moins_flag_handler(t_data *elem)
{
	int		len;
	int		i;
	int		range;
	char	*str;
	char	*buf;

	len = ft_strlen(elem->buffer);
	if (elem->width <= len)
		return ;
	range = elem->width - len;
	str = ft_strnew(elem->width);
	i = 0;
	while (range--)
		str[i++] = ' ';
	buf = elem->buffer;
	elem->buffer = ft_strjoin(buf, str);
	if (elem->wmalloc)
		free(buf);
	elem->wmalloc = 1;
	free(str);
}
