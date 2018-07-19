/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 17:54:47 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/19 18:26:11 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_data	*begin_lst;
	va_list	ap;

	va_start(ap, format);
	begin_lst = ft_parser(format);
    ft_test_print_list(&begin_lst);
	//begin_lst = ft_formatter(begin_lst, ap);
	va_end(ap);
	//ft_printer(begin_lst);
	return (0);
}