/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 09:33:29 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/08 21:43:03 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libftprintf.h"

size_t	ft_wcharlen(wchar_t wc)
{
	int	j;

	j = 0;
	if (wc <= 127)
		j += 1;
	else if (wc <= 2047)
		j += 2;
	else if (wc <= 65535)
		j += 3;
	else if (wc <= 1114111)
		j += 4;
	return (j);
}
