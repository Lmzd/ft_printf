/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 17:58:51 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/05/10 22:59:06 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_data		*ft_create_data_elem(char **str, int id)
{
	t_data	*curr;

	if (!(curr = (t_data*)malloc(sizeof(t_data))))
		return (NULL);
	curr->index = id;
	curr->text = ft_strcut(str, '%');
	if (**str)
		curr->regex = ft_find_regex(str);
	curr->next = NULL;
	return(curr);
}

/*
**	Take the format string recieve in arg cut it to store the regex
**	each % will as a personnal link
*/

t_data		*ft_parser_format(const char *format)
{
	char 	*str;
	t_data	*begin;
	t_data	*curr;
	int 	id;

	id = 0;
	str = ft_strdup(format);
	curr = NULL;
	begin = ft_create_data_elem(&str, id);
	while (*str)
	{	
		curr = ft_create_data_elem(&str, ++id);
		ft_append(&begin, curr);
	}
	return(begin);
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
		elem = ft_parser_option_checker(elem);
		printf("Type : %c\n", elem->type);
		printf("spce : %d\n", elem->flags.spaces);
		printf("hash : %d\n", elem->flags.hashtag);
		printf("zero : %d\n", elem->flags.zero);
		printf("plus : %d\n", elem->flags.plus);
		printf("moin : %d\n", elem->flags.moins);
		printf("Widt : %d\n", elem->width);
		printf("Prec : %d\n", elem->preci);
		printf("=========\n\n\n");
		elem = elem->next;
	}
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