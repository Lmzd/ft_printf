/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_options_checker.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 19:15:51 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/22 19:08:20 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_utils_parser.h"

void    ft_parser_flags_checker(t_data *elem, char *regex)
{
    elem->flags.plus = ft_strhas_char(regex, '+');
	elem->flags.dash = ft_strhas_char(regex, '-');
	elem->flags.hashtag = ft_strhas_char(regex, '#');
	elem->flags.spaces = ft_strhas_char(regex, ' ');
	elem->flags.zero = ft_strhaszero(regex, '0');
}

void    ft_parser_precision_and_width(t_data *elem, char *regex)
{
    if (ft_strhas_digit(regex))
    {
        if (ft_strhas_char(regex, '.')) 
        {
            if (elem->flags.zero)
                elem->width = ft_parser_get_zero_flag_width(ft_cutstr(regex, '.'));
            else
                elem->width = ft_parser_get_width(regex);
            elem->precision = ft_parser_get_precision(regex);
        } else {
            if (elem->flags.zero)
                elem->width = ft_parser_get_zero_flag_width(regex);
            else   
                elem->width = ft_parser_get_width(regex);
            elem->precision = -1;
        }
    } else {
        elem->width = -1;
        elem->precision = -1;
    }
}

void    ft_parser_modifier_checker(t_data *elem, char *regex)
{
    elem->modifier.h = ft_strhas_char(regex, 'h');
    elem->modifier.l = ft_strhas_char(regex, 'l');
    elem->modifier.j = ft_strhas_char(regex, 'j');
    elem->modifier.z = ft_strhas_char(regex, 'z');
    elem->modifier.hh = ft_strhas_str(regex, "hh");
    elem->modifier.ll = ft_strhas_str(regex, "ll");
}

void    ft_parser_options_checker(t_data *elem)
{
	int		len;
	char 	*regex;

	regex = ft_strdup(elem->expression);
	len = ft_strlen(regex);
	elem->type = regex[len - 1];
	ft_parser_flags_checker(elem, regex);
    ft_parser_precision_and_width(elem, regex);
    ft_parser_modifier_checker(elem, regex);
	free(regex);
}