/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_get_text_and_expression.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 11:55:55 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/22 18:57:02 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_utils_parser.h"
void    ft_parser_get_text_and_expression(t_data *elem, char **str)
{
    elem->text = ft_strcut(str, '%');
	if (**str)
		elem->expression = ft_parser_find_regex(str);
}