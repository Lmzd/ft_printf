/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_get_regex_len.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 18:06:26 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/06 07:01:44 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_utils_parser.h"

int		ft_parser_check_regex_char(char c)
{
	int i;

	i = 0;
	while (CHAR_ON[i] != '\0')
	{
		if (c == CHAR_ON[i])
			return (1);
		i++;
	}
	return (0);
}

int		ft_parser_get_regex_len(char **src)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	len = 0;
	while ((*src)[i] != '\0')
	{
		j = 0;
		if (ft_parser_check_regex_char((*src)[i]))
		{
			while (TYPES[j] != '\0')
			{
				if ((*src)[i] == TYPES[j])
					return (++len);
				j++;
			}
		}
		else
			break ;
		i++;
		len++;
	}
	return (len);
}
