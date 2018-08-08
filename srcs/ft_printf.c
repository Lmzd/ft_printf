/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 17:54:47 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/08 08:51:24 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_printf(const char *format, ...)
{
	t_data	*begin_lst;
	va_list	ap;
	int		len;
	int		erno;

	va_start(ap, format);
	begin_lst = ft_parser(format);
	erno = ft_formatter(begin_lst, ap);
	va_end(ap);
	if (erno == 1)
	{
		len = ft_counter(begin_lst);
		ft_printer(begin_lst);
	}
	else
		len = -1;
	ft_free_structure(&begin_lst);
	return (len);
}
