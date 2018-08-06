/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_get_width_precision.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 00:25:04 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/06 01:53:00 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

int		ft_parser_get_width_precision(char *str)
{
	int		i;
	int		res;

	i = 0;
	while ((str[i] <= 47 || str[i] >= 58) && str[i])
		i++;
	res = ft_atoi(str + i);
	free(str);
	return ((!res) ? -1 : res);
}
