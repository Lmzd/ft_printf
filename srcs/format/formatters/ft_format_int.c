/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pblouin <pblouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 14:39:09 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/21 14:48:45 by pblouin          ###   ########.fr       */
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
    elem->buffer = ft_itoa_intmax(value);
}


void	ft_format_int(t_data *elem, va_list ap)
{
    char *value;

    ft_format_int_modifier(elem, ap);
    ft_format_width_handler(elem);
    ft_format_plus_flag_handler(elem);
}
