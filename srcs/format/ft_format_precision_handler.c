/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_precision_handler.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:28:40 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/22 18:59:35 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void    ft_format_precision_handler_helper(t_data *elem, char *str)
{
    char    *res;
    
    if (elem->neg)
        res = ft_strjoin("-", str);
    else if (elem->flags.plus) 
        res = ft_strjoin("+", str);
    else if(elem->flags.spaces)
        res = ft_strjoin(" ", str);
    elem->buffer = ft_strdup(res);
    free(res);
}


void    ft_format_precision_handler(t_data *elem)
{
    int     len;
    int     preci;
    char    *buf;
    char    *str;
    
    buf = ft_strdup(elem->buffer);
    len = ft_strlen(buf);
    preci = elem->precision;
    if (elem->precision < len)
        return ;
    str = ft_strnew(preci);
    while (len--)
        str[--preci] = buf[len];
    while (preci--)
        str[preci] = '0';
    if (elem->flags.plus || elem->flags.spaces || elem->neg)
       ft_format_precision_handler_helper(elem, str);
    else 
        elem->buffer = ft_strdup(str);
    free(str);
}