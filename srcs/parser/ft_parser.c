/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pblouin <pblouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 17:58:51 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/19 17:44:39 by pblouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

 
/*
**	Take the format string recieve in arg cut it to store the regex
**	each % will be a unique list element
*/

t_data		*ft_parser_format(const char *format)
{
	char 	*str;
	char    *str_mem;
    t_data	*begin_list;
	t_data	*curr;

    str_mem = str;
	str = ft_strdup(format);
	begin_list = curr;
	while (*str)
	{
		curr = ft_list_create_data_elem();
		curr = ft_parser_get_text_and_expression(curr, &str);
		if (curr->expression != NULL)
		{
			curr = ft_parser_options_checker(curr);
		}
		ft_list_append(&begin_list, curr);
	}
    free(str_mem);
	return(begin_list);
}
 
t_data		*ft_parser(const char *format)
{
	t_data	*begin;

    begin = ft_parser_format(format);
    ft_test_print_list(&begin);
    return (begin);
}