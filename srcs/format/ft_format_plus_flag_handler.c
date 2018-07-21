/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_plus_flag_handler.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pblouin <pblouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 14:23:26 by pblouin           #+#    #+#             */
/*   Updated: 2018/07/21 14:47:41 by pblouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_format_plus_flag_handler(t_data *elem)
{
	int		len;
	int 	width;
	int		index;
	char 	*str;

	if (!elem->flags.plus)
		return ;
	width = elem->width;
	len = ft_strlen(elem->buffer);
	if (len >= width)
	{
		if (!(str = (char*)malloc(sizeof(char) * len + 2)))
			return ;
		str[0] = '+';
		 elem->buffer = ft_strcat(str, elem->buffer);
	} else {
		if (elem->flags.zero)
			elem->buffer[0] = '+';
		else {
			index = 0;
			while (elem->buffer[index] < '0' && elem->buffer[index] > '9')
				index++;
			index--;
			elem->buffer = ft_strreplace(elem->buffer, '+', index);
		}
	}
}
