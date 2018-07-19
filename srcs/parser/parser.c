/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 17:58:51 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/19 10:07:38 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
**	Take the all list when we know the type of data recieve
**	and ask for it in the good cast
*/

t_data		*ft_parser_content(t_data **list, va_list ap)
{
    t_data *begin;
    t_data *curr;

    begin = *list;
    curr = ft_parser_va_arg_get_argument(begin, ap);
    while (curr->next)
    {
        curr = curr->next;
        curr = ft_parser_va_arg_get_argument(curr, ap);
    }
    return (begin);
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
 
t_data		*ft_parser(const char *format, va_list ap)
{
	t_data	*begin;

    begin = ft_parser_format(format);
    begin = ft_parser_content(&begin, ap);
    ft_test_print_list(&begin);
    return (NULL);
}