/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_get_zero_flag_width_precision.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 00:34:27 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/06 01:52:55 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

int		ft_parser_get_zero_flag_width_precision(char *reg)
{
	int		i;
	int		len;
	char	*src;

	i = 0;
	len = 0;
	src = reg;
	if (!reg)
	{
		free(src);
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
	free(src);
	return ((!len) ? -1 : len);
}