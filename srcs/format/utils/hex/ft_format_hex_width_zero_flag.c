/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_hex_width_zero_flag.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 07:01:41 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/07 07:04:35 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/libftprintf.h"

void	ft_format_hex_width_zero_flag_helper(t_data *elem, char *str, int width,
	int len)
{
	while (len--)
		str[--width] = elem->buffer[len];
	while (width--)
		str[width] = '0';
	(!(elem->type == 'O' || elem->type == 'o')) ? str[1] = 'x' : str[1];
	free(elem->buffer);
	elem->buffer = ft_strdup(str);
}

void	ft_format_hex_width_zero_flag(t_data *elem, char *prefix,
	char *str, int width)
{
	int		len;
	int		range;
	char	*buf;

	len = ft_strlen(elem->buffer);
	range = width - len;
	if (range >= 2 && (elem->flags.hash || elem->type == 'p'))
		ft_format_hex_width_zero_flag_helper(elem, str, width, len);
	else if ((elem->flags.hash && width < len + 2) || elem->type == 'p')
	{
		buf = elem->buffer;
		elem->buffer = ft_strjoin(prefix, buf);
		free(buf);
	}
	else
	{
		while (len--)
			str[--width] = elem->buffer[len];
		while (width--)
			str[width] = '0';
		free(elem->buffer);
		elem->buffer = ft_strdup(str);
	}
}
