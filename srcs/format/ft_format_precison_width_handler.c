/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_precison_width_handler.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 18:50:24 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/22 19:33:45 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void    ft_format_precison_width_handler(t_data *elem)
{
    int     len;
    int     width;
    int     range;
    char    *buf;
    char    *str;

    buf = ft_strdup(elem->buffer);
    len = ft_strlen(buf);
    width = elem->width;
    if (width <= len)
        return ;
    str = ft_strnew(width - len);
    range = width - len;
    while(range--)
        str[range] = ' ';
    elem->buffer = ft_strdup(ft_strjoin(str, buf));
    free(str);
    free(buf);
}