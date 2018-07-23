/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 14:40:00 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/23 23:21:24 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

void    ft_format_char_modifier(t_data *elem, va_list ap)
{
    char *value;
    t_modifier modifier;

    modifier = elem->modifier;
    value = ft_strnew(1);
    if (modifier.ll)
        modifier.l = 0;
    if (modifier.l || elem->type == 'C')
    {
        elem->value = va_arg(ap, wchar_t);
        elem->null = 0;
    }
    else if (elem->type == 'c')
    {
        value[0] = (unsigned char)va_arg(ap, int);
        elem->value = 0;
        elem->null = (value[0] == 0) ? 1 : 0;
    }
    elem->neg = 0;
    elem->buffer = value;
}

void    ft_format_char(t_data *elem, va_list ap)
{
    ft_format_char_modifier(elem, ap);
    if (!elem->flags.dash \
       || (elem->flags.dash && (elem->width < elem->buffer_len)))
    {
            ft_format_width_handler(elem);
            ft_format_plus_flag_handler(elem);
            ft_format_space_flag_handler(elem);
    } else {
            ft_format_moins_flag_handler(elem);
            ft_format_moins_flag_space_or_plus_handler(elem);
        
    }
    // ft_format_null_value(elem);
} 