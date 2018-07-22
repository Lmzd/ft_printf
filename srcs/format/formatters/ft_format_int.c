/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pblouin <pblouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 14:39:09 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/22 16:09:13 by pblouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

void    ft_format_int_modifier(t_data *elem, va_list ap)
{
    intmax_t value;
    t_modifier modifier;

    modifier = elem->modifier;
    if (modifier.hh)
    {
        modifier.h = 0;
        value = (char)va_arg(ap, int);
    } else if (modifier.h)
        value = (short)va_arg(ap, int);
    else if (modifier.l)
        value = va_arg(ap, long int);
    else if (modifier.ll)
        value = va_arg(ap, long long int);
    else if (modifier.j)
        value = va_arg(ap, intmax_t);
    else if (modifier.z)
        value = va_arg(ap, size_t);
    else
        value = va_arg(ap, int);
    elem->neg = (value >= 0) ? 0 : 1;
    elem->buffer = ft_itoa_base_intmax(ft_abs_intmax(value), 10);
    elem->buffer_len = ft_strlen(elem->buffer);
}


void	ft_format_int(t_data *elem, va_list ap)
{
    char *value;

    ft_format_int_modifier(elem, ap);
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

}
