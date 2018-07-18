/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 17:58:51 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/18 16:01:23 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
**	Take the regex string store in the struct  && to store
**			the flag
**			the width
**			the precision
**
**	each % will as a personnal link
*/

t_data		*ft_parser_parse_expression(t_data *elem)
{
	elem = ft_parser_flags_checker(elem);

	return elem;
}

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


	str = ft_strdup(format);
    str_mem = str;
	curr = NULL;
	begin_list = ft_list_create_data_elem();
	while (*str)
	{
		curr = ft_list_create_data_elem();
		curr = ft_parser_get_text_and_expression(curr, &str);
		if (curr->expression)
		{
			curr = ft_parser_parse_expression(curr);
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