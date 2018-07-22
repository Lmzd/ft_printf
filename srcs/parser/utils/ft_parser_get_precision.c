/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_get_precision.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 17:42:46 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/22 17:19:59 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_utils_parser.h"

int		ft_parser_get_precision(char *regex)
{
	int		len;

	while (*regex != '.')
		regex++;
    regex++;
	len = ft_atoi(regex);
	return ((len < 0) ? -1 : len);
}