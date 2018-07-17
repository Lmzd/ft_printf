/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_option_checker.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 18:01:37 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/17 18:04:29 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

/*
**	Fill the options variable and type in a structure element
**	from regex
*/

t_data	*ft_parser_option_checker(t_data *elem)
{
	t_data 	*curr;
	int		len;
	char 	*regex;
	char	*width;

	curr = elem;
	regex = ft_strdup(curr->regex);
	if (!regex)
		return (curr);
	len = ft_strlen(regex);
	curr->type = regex[len - 1];
	curr->flags.plus = ft_strhas(regex, '+');
	curr->flags.moins = ft_strhas(regex, '-');
	curr->flags.hashtag = ft_strhas(regex, '#');
	curr->flags.spaces = ft_strhas(regex, ' ');
	curr->flags.zero = ft_strhas(regex, '0');
	if (ft_strhas(regex, '.'))
	{
		if (curr->flags.zero)
			curr->width = ft_parser_get_width_zero_opt(ft_cutstr(regex, '.'));
		else
			curr->width = ft_parser_get_width(regex);
		curr->preci = ft_parser_get_precision(regex);	
	}
	curr->width = ft_parser_get_width(regex);
	free(regex);
	return (curr);
}
