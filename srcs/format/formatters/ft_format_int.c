/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pblouin <pblouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 14:39:09 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/20 16:37:48 by pblouin          ###   ########.fr       */
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
    }
    if (modifier.h)
        value = (short)va_arg(ap, int);
    if (modifier.l)
        value = va_arg(ap, long int);
    if (modifier.ll)
        value = va_arg(ap, long long int);
    if (modifier.j)
        value = va_arg(ap, intmax_t);
    if (modifier.z)
        value = va_arg(ap, size_t);
        
    elem->buffer = ft_itoa_intmax(value);
}


void	ft_format_int(t_data *elem, va_list ap)
{
    char *value;

    ft_format_int_modifier(elem, ap);
    ft_format_width_handler(elem);
}
