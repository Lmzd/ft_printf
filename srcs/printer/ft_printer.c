/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 13:33:57 by pblouin           #+#    #+#             */
/*   Updated: 2018/08/07 00:29:32 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_printer_helper(t_data *elem)
{
	if (elem->value || (elem->type == 'c' && elem->modifier.l)
		|| elem->type == 'C')
		ft_print_unicode(elem);
	else if (elem->type == 'S' && elem->flags.dash
		&& (elem->width > (int)ft_strwlen(elem->wbuffer)))
	{
		ft_print_wchar(elem);
		write(1, elem->buffer, ft_strlen(elem->buffer));
	}
	else if (elem->buffer)
		write(1, elem->buffer, ft_strlen(elem->buffer));
	else if (elem->wbuffer)
		ft_print_wchar(elem);
}

void	ft_printer(t_data *elem)
{
	t_data	*begin;

	if (!elem)
		return ;
	begin = elem;
	while (elem)
	{
		if (elem->text)
			write(1, elem->text, ft_strlen(elem->text));
		if (elem->null && (elem->type == 'c' || elem->type == 'C'))
			ft_print_null_bite(elem, ft_strlen(elem->buffer));
		else
			ft_printer_helper(elem);
		elem = elem->next;
	}
	elem = begin;
}
