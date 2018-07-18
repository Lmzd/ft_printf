/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_options_checker.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 19:15:51 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/18 22:11:39 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_utils_parser.h"

t_data  *ft_parser_flags_checker(t_data *elem, char *regex)
{
    t_data 	*curr;

    curr = elem;
    curr->flags.plus = ft_strhas_char(regex, '+');
	curr->flags.dash = ft_strhas_char(regex, '-');
	curr->flags.hashtag = ft_strhas_char(regex, '#');
	curr->flags.spaces = ft_strhas_char(regex, ' ');
	curr->flags.zero = ft_strhas_char(regex, '0');
    return (curr);
}

t_data  *ft_parser_precision_and_width(t_data *elem, char *regex)
{
    t_data 	*curr;

    curr = elem;
    if (ft_strhas_char(regex, '.')) 
    {
        if (curr->flags.zero)
            curr->width = ft_parser_get_zero_flag_width(ft_cutstr(regex, '.'));
        else
            curr->width = ft_parser_get_width(regex);
        curr->precision = ft_parser_get_precision(regex);
    } else
        curr->width = ft_parser_get_width(regex);
    return (curr);	
}

t_data  *ft_parser_modifier_checker(t_data *elem, char *regex)
{
    t_data 	*curr;

    curr = elem;
    curr->modifier.h = ft_strhas_char(regex, 'h');
    curr->modifier.l = ft_strhas_char(regex, 'l');
    curr->modifier.j = ft_strhas_char(regex, 'j');
    curr->modifier.z = ft_strhas_char(regex, 'z');
    curr->modifier.hh = ft_strhas_str(regex, "hh");
    curr->modifier.ll = ft_strhas_str(regex, "ll");
    return (curr);
}

t_data	*ft_parser_options_checker(t_data *elem)
{
	t_data 	*curr;
	int		len;
	char 	*regex;

	curr = elem;
	regex = ft_strdup(curr->expression);
	len = ft_strlen(regex);
	curr->type = regex[len - 1];
	curr = ft_parser_flags_checker(curr, regex);
   // curr = ft_parser_precision_and_width(curr, regex);
    curr = ft_parser_modifier_checker(curr, regex);
	free(regex);
	return (curr);
}