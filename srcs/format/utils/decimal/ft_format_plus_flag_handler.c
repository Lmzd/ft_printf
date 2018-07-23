/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_plus_flag_handler.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 14:23:26 by pblouin           #+#    #+#             */
/*   Updated: 2018/07/23 20:07:55 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/ft_printf.h"

void    ft_format_plus_flag_handler_helper(t_data *elem, char *buf, int len)
{
    char *str;
    
    str = ft_strnew(len + 2);
    str[0] = '+';
    ft_strcat(str, buf);
    elem->buffer = ft_strdup(str);
    free(str);
    free(buf);
}

void	ft_format_plus_flag_handler(t_data *elem)
{
	int		len;
	int 	width;
	int		index;
	char 	*str;
    char    *buf;

	if (!elem->flags.plus || elem->neg || elem->type == 'c' || elem->type == 'C')
		return ;
	width = elem->width;
    buf = ft_strdup(elem->buffer);
	len = ft_strlen(buf);
	if (len >= width && !elem->flags.zero && buf[0] != ' ')
		ft_format_plus_flag_handler_helper(elem, buf, len);
	else {
		if (elem->flags.zero)
			elem->buffer[0] = '+';
		else {
			index = 0;
			while (buf[index] < '0' || buf[index] > '9')
				index++;
			elem->buffer = ft_strreplace(elem->buffer, '+', --index);
		}
	}
}
