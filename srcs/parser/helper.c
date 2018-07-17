/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 22:41:23 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/06 14:47:41 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		ft_parser_get_width_zero_opt(char *reg)
{
	char 	*width;
	int		i;
	int 	len;

	i = 0;
	len = 0;
	while (*reg != '0')
		reg++;
	while (reg[++i] != '\0')
		if (reg[i] > 47 && reg[i] < 58)
			len++;
	if (!(width = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	i = 0;	
	while (reg[++i] != '\0')
		if (reg[i] > 47 && reg[i] < 58)
			width[i - 1] = reg[i];
	width[len] = '\0';
	return (ft_atoi(width));
}

int		ft_parser_get_width(char *reg)
{
	char 	*width;
	int		i;
	int 	len;

	i = 0;
	len = 0;
	while (reg[i++] != '\0')
		if (reg[i] > 47 && reg[i] < 58)
			len++;
	printf("len : %d\n", len);
	if (!(width = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	i = 0;	
	while (reg[i] != '\0')
	{
		printf("%c\n", reg[i]);
		if (reg[i] > 47 && reg[i] < 58)
			width[i] = reg[i];
		i++;
	}
	width[i] = '\0';
	printf("len : %s\n", width);
	return (ft_atoi(width));
}