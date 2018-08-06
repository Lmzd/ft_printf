/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_plus_flag_handler.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 14:23:26 by pblouin           #+#    #+#             */
/*   Updated: 2018/08/06 07:49:48 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/ft_printf.h"

void	ft_format_plus_flag_handler_helper(t_data *elem)
{
	char *buf;
	char *res;

	buf = elem->buffer;
	res = ft_strjoin("+", buf);
	free(elem->buffer);
	elem->buffer = res;
}

void	ft_format_plus_flag_helper(t_data *elem, int len)
{
	char	*buf;
	char	*res;
	int		i;

	buf = ft_strdup(elem->buffer);
	i = 0;
	if (elem->flags.zero && elem->width == len && buf[0] == '0')
		elem->buffer[0] = '+';
	else if (elem->flags.zero)
	{
		free(elem->buffer);
		elem->buffer = ft_strjoin("+", buf);
	}
	else
	{
		while (buf[i] < '0' || buf[i] > '9')
			i++;
		res = ft_strreplace(buf, '+', --i);
		elem->buffer = res;
	}
	free(buf);
}

void	ft_format_plus_flag_handler(t_data *elem)
{
	int		len;
	int		width;

	if (elem->flags.plus != 1 || elem->neg || elem->type == 'c'
		|| elem->type == 'C' || elem->type == 'u' || elem->type == 'U')
		return ;
	width = elem->width;
	len = ft_strlen(elem->buffer);
	if (len >= width && !elem->flags.zero && elem->buffer[0] != ' ')
		ft_format_plus_flag_handler_helper(elem);
	else
		ft_format_plus_flag_helper(elem, len);
}
