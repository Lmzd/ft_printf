/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 19:24:12 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/02 08:26:29 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strwlen(wchar_t *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if ((int)str[i] < 0x7F)
			j += 1;
		else if ((int)str[i] < 0x7FF)
			j += 2;
		else if ((int)str[i] < 0xFFFF)
			j += 3;
		else if ((int)str[i] < 0x10FFFF)
			j += 4;
		i++;
	}
	return (j);
}
