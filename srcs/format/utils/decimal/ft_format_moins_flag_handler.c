/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_moins_flag_handler.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 17:07:37 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/23 19:27:12 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/ft_printf.h"

void    ft_format_moins_flag_handler(t_data *elem)
{
    char    *str;
    char    *buf;
    int     range;
    int     len;
    int     width;

    width = elem->width;
    if (width < 0 || !elem->flags.dash)
        return ;
    len = ft_strlen(elem->buffer);
    buf = ft_strdup(elem->buffer);
    str = ft_strnew(width - len);
    range = width - len;
    if (elem->neg)
    {
        str[0] = '-';
        range--;
    }
    while (range--)
        str[--width] = ' ';
    while (len--)
        str[--width] = buf[len];
    if (elem->null && (elem->type == 'c' || elem->type == 'C'))
        str[ft_strlen(str) - 1] = 0;
    elem->buffer = ft_strdup(str);
    free(str);
}