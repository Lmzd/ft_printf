/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_va_arg_get_argument.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 21:53:33 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/18 22:01:01 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/ft_utils_parser.h"

t_data  *ft_parser_va_arg_get_argument(t_data *elem, va_list ap)
{
    t_data *curr;

    curr = elem;
    if (curr->type == 's')
        curr = ft_parser_va_arg_get_string_arg(curr, ap);
    if (curr->type == 'f' || curr->type == 'e' || curr->type == 'E' 
            || curr->type == 'g' || curr->type == 'G')
        curr = ft_parser_va_arg_get_double_arg(curr, ap);
    if (curr->type == 'd' || curr->type == 'D' || curr->type == 'i'
            || curr->type == 'c' || curr->type == 'C' || curr->type == 'u'
            || curr->type == 'U' || curr->type == 'o' || curr->type == 'O'
            || curr->type == 'x' || curr->type == 'X')
        curr = ft_parser_va_arg_get_int_arg(curr, ap);
    
    return (curr);
}