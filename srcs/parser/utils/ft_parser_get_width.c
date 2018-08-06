/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_get_width.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 18:21:43 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/05 04:49:42 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_utils_parser.h"

int		ft_parser_get_width(char *str)
{
	int		i;
	int		res;

	i = 0;
	while ((str[i] <= 47 || str[i] >= 58) && str[i])
		i++;
	res = ft_atoi(str + i);
	return ((!res) ? -1 : res);
}
