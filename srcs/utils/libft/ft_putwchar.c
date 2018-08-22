/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 23:01:52 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/21 21:35:08 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libftprintf.h"

void	ft_putwchar(wchar_t wc)
{
	if ((wc > 55295 && wc < 57344) || wc > 1114111 || wc < 0)
		return ;
	else if (wc <= 127 || (MB_CUR_MAX == 1 && (wc > 127 && wc <= 255)))
		ft_putchar(wc);
	else if (wc <= 2047)
	{
		ft_putchar((wc >> 6) | 0xC0);
		ft_putchar((wc & 0x3F) | 0x80);
	}
	else if (wc <= 65535)
	{
		ft_putchar((wc >> 12) | 0xE0);
		ft_putchar(((wc >> 6) & 0x3F) | 0x80);
		ft_putchar((wc & 0x3F) | 0x80);
	}
	else if (wc <= 1114111)
	{
		ft_putchar((wc >> 18) | 0xF0);
		ft_putchar(((wc >> 12) & 0x3F) | 0x80);
		ft_putchar(((wc >> 6) & 0x3F) | 0x80);
		ft_putchar((wc & 0x3F) | 0x80);
	}
}
