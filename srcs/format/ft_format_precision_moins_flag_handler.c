/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_precision_moins_flag_handler.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 19:40:52 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/22 22:02:44 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void    ft_format_precision_moins_flag_handler_helper(t_data *elem, char *str, char *buf)
{
    char *res;
    char *neg;

    if (elem->neg)
    {
        res = ft_strjoin(buf, str);
        neg = ft_strjoin("-", res);
        elem->buffer = ft_strdup(neg);
        free(neg);
        free(res);
    }
    else
        elem->buffer = ft_strdup(ft_strjoin(buf, str));
}

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
    ft_format_precision_moins_flag_handler_helper(elem, str, buf);
    free(str);
    free(buf);
}