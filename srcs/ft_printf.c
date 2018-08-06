/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 17:54:47 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/06 07:49:20 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_data	*begin_lst;
	va_list	ap;

	va_start(ap, format);
	begin_lst = ft_parser(format);
	ft_formatter(begin_lst, ap);
	ft_printer(begin_lst);
	va_end(ap);
	ft_free_structure(&begin_lst);
	return (0);
}
