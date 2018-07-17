/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 17:58:51 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/17 20:38:46 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_data		*ft_create_data_elem(char **str)
{
	t_data	*curr;

	if (!(curr = (t_data*)malloc(sizeof(t_data))))
		return (NULL);
	curr->text = ft_strcut(str, '%');
	if (**str)
		curr->expression = ft_parser_find_regex(str);
	curr->next = NULL;
	return(curr);
}

/*
**	Take the format string recieve in arg cut it to store the regex
**	each % will be a unique list element
*/

t_data		*ft_parser_format(const char *format)
{
	char 	*str;
	t_data	*begin_list;
	t_data	*curr;

	str = ft_strdup(format);
	curr = NULL;
	begin_list = ft_create_data_elem(&str);
	while (*str)
	{
		curr = ft_create_data_elem(&str);
		ft_list_append(&begin_list, curr);
	}
	return(begin_list);
}

/*
**	Take the regex string store in the struct  && to store
**			the flag
**			the width
**			the precision
**
**	each % will as a personnal link
*/

t_data		*ft_parser_regex(t_data **begin)
{
	t_data *elem;

	elem = *begin;
	while (elem)
	{
		elem = ft_parser_flags_checker(elem);
		printf("Type      : %c\n", elem->type);
		printf("Space     : %d\n", elem->flags.spaces);
		printf("Hash      : %d\n", elem->flags.hashtag);
		printf("Zero      : %d\n", elem->flags.zero);
		printf("Plus      : %d\n", elem->flags.plus);
		printf("Dash      : %d\n", elem->flags.dash);
		printf("Width     : %d\n", elem->width);
		printf("Precision : %d\n", elem->precision);
		printf("=========\n\n\n");
		elem = elem->next;
	}
	return NULL;
}

/*
**	Take the all list when we know the type of data recieve
**	and ask for it in the good cast
*/

t_data		*ft_parser_content(t_data **begin, va_list ap)
{

}

t_data		*ft_parser(const char *format, va_list ap)
{
	t_data	*begin;

	begin = ft_parser_format(format);
	begin = ft_parser_regex(&begin);

}