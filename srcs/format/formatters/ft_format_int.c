/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 14:39:09 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/20 15:47:18 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"
#include "../../../includes/ft_format.h"

void    ft_format_int_modifier(t_data *elem, ap)
{
    intmax_t value;
    t_modifier modifier;

    modifier = elem->modifier;
    if (modifier->hh)
    {
        modifier->h = 0;
        value = va_arg(ap, char);
    }
    if (modifier->h)
        value = va_arg(ap, short)
    if (modifier->l)
        value = va_arg(ap, long);
    if (modifier->ll)
        value = va_arg(ap, long long);
    if (modifier->j)
        value = va_arg(ap, intmax_t);
    if (modifier->z)
        value = va_arg(ap, size_t);
    elem->buffer = ft_itoa_intmax(value);
}


void	ft_format_int(t_data *elem, va_list ap)
{
    char *value;

    ft_format_int_modifier(elem, ap);
}
