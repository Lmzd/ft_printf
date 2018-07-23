/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_null_value.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 23:13:40 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/23 15:21:31 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/ft_printf.h"

void    ft_format_null_value(t_data *elem)
{
    char *buf;
    int len;

    buf = ft_strdup(elem->buffer);
    len = ft_strlen(buf);
    if (elem->null)
    {
        if (!elem->precision && elem->width >= 1)
            buf = ft_strreplace(buf, ' ', len - 1);
        if (!elem->precision && elem->width == -1)
            buf = "";
    }
    elem->buffer = ft_strdup(buf);
}