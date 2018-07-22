/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_precison_width_handler.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 18:50:24 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/22 22:59:48 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void    ft_format_precison_width_handler_helper(t_data *elem, char *str, char *buf)
{
    char *res;
    char *neg;

    if (elem->neg && (elem->width < elem->precision))
    {
        res = ft_strjoin(str, buf);
        neg = ft_strjoin("-", res);
        elem->buffer = ft_strdup(neg);
        free(neg);
        free(res);
    }
    else
        elem->buffer = ft_strdup(ft_strjoin(str, buf));
}

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
    if (elem->neg && (width >= elem->precision))
        buf = ft_strjoin("-", buf);
    if (width <= len)
    {
        if (elem->neg && width < elem->precision)
            buf = ft_strjoin("-", buf);
        elem->buffer = ft_strdup(buf);
        return ;
    }
    str = ft_strnew(width - len);
    range = width - len - elem->neg;
    while(range--)
        str[range] = ' ';
    ft_format_precison_width_handler_helper(elem, str, buf);
    free(str);
    free(buf);
}