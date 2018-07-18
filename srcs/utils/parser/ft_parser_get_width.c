/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_get_width.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 18:21:43 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/18 18:35:37 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_utils_parser.h"

int		ft_parser_get_width(char *reg)
{
	int		i;
	int 	len;

    i = 0;
    while (*reg <= 47 || *reg >= 58)
        reg++;
    len = ft_atoi(reg);
	return (len);
}