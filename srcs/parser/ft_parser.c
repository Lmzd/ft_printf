/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 17:58:51 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/22 20:44:24 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
**	Take the format string recieve in arg cut it to store the regex
**	each % will be a unique list element
*/

t_data		*ft_parser(const char *format)
{
	char 	*str;
	char    *str_mem;
    t_data	*begin_list;
	t_data	*curr;

    str_mem = str;
	str = ft_strdup(format);
    curr = NULL;
	begin_list = curr;
	while (*str)
	{
		curr = ft_list_create_data_elem();
		ft_parser_get_text_and_expression(curr, &str);
		if (curr->expression != NULL)
			ft_parser_options_checker(curr);
		else
            ft_parser_put_default(curr);
		ft_list_append(&begin_list, curr);
	}
    free(str_mem);
	return(begin_list);
}