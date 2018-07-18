/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_get_width.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 18:21:43 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/18 13:58:38 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_utils_parser.h"

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
	// printf("len : %d\n", len);
	if (!(width = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	i = 0;	
	while (reg[i] != '\0')
	{
		// printf("%c\n", reg[i]);
		if (reg[i] > 47 && reg[i] < 58)
			width[i] = reg[i];
		i++;
	}
	width[i] = '\0';
	// printf("len : %s\n", width);
	return (ft_atoi(width));
}