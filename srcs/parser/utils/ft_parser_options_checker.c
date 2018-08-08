/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_options_checker.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 19:15:51 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/07 05:47:02 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_utils_parser.h"

void	ft_parser_flags_checker(t_data *elem, char *regex)
{
	elem->flags.dash = ft_strhas_char(regex, '-');
	elem->flags.hash = ft_strhas_char(regex, '#');
	elem->flags.spaces = ft_strhas_char(regex, ' ');
	elem->flags.zero = ft_strhas_zero(regex, '0');
	elem->flags.plus = ft_strhas_char(regex, '+');
}

void	ft_parser_precision_and_width(t_data *elem, char *regex)
{
	if (ft_strhas_digit(regex))
	{
		if (ft_strhas_char(regex, '.'))
		{
			elem->width = (elem->flags.zero)
				? ft_parser_get_zero_flag_width_precision(ft_cutstr(regex, '.'))
				: ft_parser_get_width_precision(ft_cutstr(regex, '.'));
			elem->precision = ft_parser_get_precision(regex);
		}
		else
		{
			elem->width = (elem->flags.zero)
				? ft_parser_get_zero_flag_width(regex)
				: ft_parser_get_width(regex);
			elem->precision = -1;
		}
	}
	else
	{
		elem->precision = (ft_strhas_char(regex, '.')) ? 0 : -1;
		elem->width = -1;
	}
}

void	ft_parser_modifier_checker(t_data *elem, char *regex)
{
	elem->modifier.h = ft_strhas_char(regex, 'h');
	elem->modifier.l = ft_strhas_char(regex, 'l');
	elem->modifier.j = ft_strhas_char(regex, 'j');
	elem->modifier.z = ft_strhas_char(regex, 'z');
	elem->modifier.hh = ft_strhas_str(regex, "hh");
	elem->modifier.ll = ft_strhas_str(regex, "ll");
}

void	ft_parser_options_checker(t_data *elem)
{
	int		len;
	char	*regex;

	regex = ft_strdup(elem->expression);
	len = ft_strlen(regex);
	elem->type = regex[len - 1];
	ft_parser_flags_checker(elem, regex);
	ft_parser_modifier_checker(elem, regex);
	ft_parser_precision_and_width(elem, regex);
	ft_strdel(&regex);
}
