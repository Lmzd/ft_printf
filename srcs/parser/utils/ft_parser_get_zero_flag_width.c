/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_get_zero_flag_width.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 18:15:58 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/06 07:27:40 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_utils_parser.h"

int		ft_parser_get_zero_flag_width(char *reg)
{
	int		i;
	int		len;
	char	*src;

	i = 0;
	len = 0;
	src = reg;
	if (!reg)
	{
		free(reg);
		return (-1);
	}
	while (*reg != '0' && *reg != '\0')
		reg++;
	reg++;
	if (*reg == '\0')
	{
		free(src);
		return (-1);
	}
	while ((*reg <= 47 || *reg >= 58) && *reg)
		reg++;
	len = ft_atoi(reg);
	return ((!len) ? -1 : len);
}
