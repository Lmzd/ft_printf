/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_va_arg_get_double_arg.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 21:03:36 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/18 22:04:19 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/ft_utils_parser.h"

t_data  *ft_parser_va_arg_get_double_arg(t_data *elem, va_list ap)
{
    t_data *curr;

    curr = elem;
    curr->d_val = va_arg(ap, double);
    return (curr);
}
