/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_get_zero_flag_width.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 18:15:58 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/22 17:14:31 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_utils_parser.h"

int		ft_parser_get_zero_flag_width(char *reg)
{
	int		i;
	int 	len;

	i = 0;
	len = 0;
    if (!reg)
        return (-1);
    while (*reg  != '0')
        reg++;
    reg++;
    while (*reg <= 47 || *reg >= 58)
        reg++;
    len = ft_atoi(reg);
	return ((!len) ? -1 : len);
}
