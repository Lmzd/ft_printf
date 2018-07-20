/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_va_arg_get_string_arg.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 21:03:44 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/18 22:04:33 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/ft_utils_parser.h"

t_data  *ft_parser_va_arg_get_string_arg(t_data *elem, va_list ap)
{
    t_data *curr;

    curr = elem;
    curr->s_val = va_arg(ap, char*);
    return (curr);
}
