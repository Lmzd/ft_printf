/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 17:54:47 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/07 00:29:31 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_data	*begin_lst;
	va_list	ap;
	int		len;

	va_start(ap, format);
	begin_lst = ft_parser(format);
	ft_formatter(begin_lst, ap);
	va_end(ap);
	len = ft_counter(begin_lst);
	ft_printer(begin_lst);
	ft_free_structure(&begin_lst);
	return (len);
}
