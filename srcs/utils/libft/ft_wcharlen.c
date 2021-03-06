/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 09:33:29 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/22 19:00:32 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libftprintf.h"

int	ft_wcharlen(wchar_t wc)
{
	int	j;

	j = 0;
	if ((wc > 55295 && wc < 57344) || wc > 1114111 || wc < 0)
		return (-1);
	else if (wc <= 127)
		j += 1;
	else if (wc <= 2047)
		j += 2;
	else if (wc <= 65535)
		j += 3;
	else if (wc <= 1114111)
		j += 4;
	return (j);
}
