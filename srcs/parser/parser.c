/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 17:58:51 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/18 19:18:38 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
**	Take the all list when we know the type of data recieve
**	and ask for it in the good cast
*/

t_data		*ft_parser_content(t_data **begin, va_list ap)
{
    return(NULL);
}
 
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


	curr = NULL;
    str_mem = str;
	str = ft_strdup(format);
	begin_list = ft_list_create_data_elem();
	while (*str)
	{
		curr = ft_list_create_data_elem();
		curr = ft_parser_get_text_and_expression(curr, &str);
		if (curr->expression != NULL)
		{
			curr = ft_parser_options_checker(curr);
		}
        ft_test_print_list_elem(curr);
		ft_list_append(&begin_list, curr);
	}
    free(str_mem);
	return(begin_list);
}
 
t_data		*ft_parser(const char *format, va_list ap)
{
	t_data	*begin;

	begin = ft_parser_format(format);
    return (NULL);
}