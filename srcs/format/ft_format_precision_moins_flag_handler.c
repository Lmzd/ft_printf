/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_precision_moins_flag_handler.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 19:40:52 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/22 19:42:22 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void    ft_format_precision_moins_flag_handler(t_data *elem)
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
    elem->buffer = ft_strdup(ft_strjoin(buf, str));
    free(str);
    free(buf);
}