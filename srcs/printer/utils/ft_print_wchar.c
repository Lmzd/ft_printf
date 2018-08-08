/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:23:42 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/07 07:04:35 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libftprintf.h"

void	ft_print_wchar(t_data *elem)
{
	wchar_t *buf;

	if (elem->null)
		ft_putstr("(null)");
	else
	{
		buf = elem->wbuffer;
		while (*buf)
		{
			if (*buf <= 127)
				ft_putchar(*buf);
			if (*buf > 127)
				ft_putwchar(*buf);
			buf++;
		}
	}
}
