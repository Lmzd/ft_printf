/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_get_text_and_expression.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 11:55:55 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/18 13:57:55 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_utils_parser.h"

t_data      *ft_parser_get_text_and_expression(t_data *elem, char **str)
{
    t_data *curr;

    curr = elem;
    curr->text = ft_strcut(str, '%');
	if (**str)
		curr->expression = ft_parser_find_regex(str);
    return (curr);
}