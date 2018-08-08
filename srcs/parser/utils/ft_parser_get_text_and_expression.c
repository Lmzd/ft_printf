/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_get_text_and_expression.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 11:55:55 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/07 07:47:30 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_utils_parser.h"

void	ft_parser_get_text_and_expression(t_data *elem, char **str)
{
	int		len;

	len = 0;
	elem->text = ft_strcut(str, '%');
	len = ft_strlen(elem->text);
	if (len == 0)
	{
		free(elem->text);
		elem->text = NULL;
	}
	if (**str)
	{
		len = ft_parser_get_regex_len(str);
		elem->expression = (len == 0) ? NULL : ft_strncut(str, len);
	}
	len = 0;
	len = ft_strlen(elem->expression);
	if (len == 0)
		elem->expression = NULL;
}
