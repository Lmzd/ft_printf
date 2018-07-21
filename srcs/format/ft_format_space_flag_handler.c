/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_space_flag_handler.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 18:36:51 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/21 19:08:55 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void    ft_format_space_flag_handler(t_data *elem)
{
    int len;
    char *str;
    char *buf;

    if (elem->flags.plus)
        return ;
    if (!elem->flags.spaces || elem->neg)
        return ;
    if (elem->width < 0) 
    {
        buf = strdup(elem->buffer);
        len = ft_strlen(buf);
        str = ft_strnew(len + 2);
        str[0] = ' ';
        elem->buffer = ft_strcat(str, buf);
    }
}