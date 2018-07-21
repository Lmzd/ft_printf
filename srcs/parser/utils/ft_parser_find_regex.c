/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_find_regex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 18:06:52 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/21 15:45:30 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_utils_parser.h"

/*
**	Find the regex in format
**	send string begin with % 
**  have to return a string with all the regex
*/

char	*ft_parser_find_regex(char **src)
{
	char	*regex;	
	int 	len;

	len = ft_parser_get_regex_len(src);
    if (len == 0)
        regex = ft_strnew(1);
    else
	    regex = ft_strncut(src, len);
	return (regex);
}