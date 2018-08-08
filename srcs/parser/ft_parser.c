/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 17:58:51 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/07 07:43:35 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

/*
**	Take the format string recieve in arg cut it to store the regex
**	each % will be a unique list element
*/

t_data		*ft_parser(const char *format)
{
	t_data	*begin_list;
	t_data	*curr;

	curr = NULL;
	begin_list = curr;
	while (*format)
	{
		curr = ft_list_create_data_elem();
		ft_parser_get_text_and_expression(curr, (char**)&format);
		if (curr->expression != NULL)
			ft_parser_options_checker(curr);
		else
			ft_parser_put_default(curr);
		ft_list_append(&begin_list, curr);
	}
	return (begin_list);
}
