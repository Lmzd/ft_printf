/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_flags_checker.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 18:15:03 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/17 20:39:37 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_utils_parser.h"

t_data	*ft_parser_flags_checker(t_data *elem)
{
	t_data 	*curr;
	int		len;
	char 	*regex;
	char	*width;

	curr = elem;
	regex = ft_strdup(curr->expression);
	if (!regex)
		return (curr);
	len = ft_strlen(regex);
	curr->type = regex[len - 1];
	curr->flags.plus = ft_strhas(regex, '+');
	curr->flags.dash = ft_strhas(regex, '-');
	curr->flags.hashtag = ft_strhas(regex, '#');
	curr->flags.spaces = ft_strhas(regex, ' ');
	curr->flags.zero = ft_strhas(regex, '0');
	if (ft_strhas(regex, '.'))
	{
		if (curr->flags.zero)
			curr->width = ft_parser_get_zero_flag_width(ft_cutstr(regex, '.'));
		else
			curr->width = ft_parser_get_width(regex);
		curr->precision = ft_parser_get_precision(regex);	
	}
	curr->width = ft_parser_get_width(regex);
	free(regex);
	return (curr);
}