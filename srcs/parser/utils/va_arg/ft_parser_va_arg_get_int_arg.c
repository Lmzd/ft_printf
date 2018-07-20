/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_va_arg_get_int_arg.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 21:03:39 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/18 22:04:29 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/ft_utils_parser.h"

t_data  *ft_parser_va_arg_get_int_arg(t_data *elem, va_list ap)
{
    t_data *curr;

    curr = elem;
    curr->i_val = va_arg(ap, int);
    return (curr);
}
