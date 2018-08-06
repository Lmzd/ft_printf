/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 09:33:29 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/02 08:00:51 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wcharlen(wchar_t c)
{
	int	j;

	j = 0;
	if (c < 0x7F)
		j = 1;
	else if (c < 0x7FF)
		j = 2;
	else if (c < 0xFFFF)
		j = 3;
	else if (c < 0x10FFFF)
		j = 4;
	return (j);
}
