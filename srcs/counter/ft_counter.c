/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 09:44:09 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/07 01:13:43 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		ft_counter_unicode(t_data *elem)
{
	int nb;

	nb = ft_strlen(elem->buffer);
	elem->buffer[--nb] = '\0';
	return (ft_strlen(elem->buffer) + ft_wcharlen(elem->value));
}

int		ft_counter(t_data *begin)
{
	t_data	*elem;
	int		len;

	elem = begin;
	len = 0;
	while (elem)
	{
		if (elem->text)
			len += ft_strlen(elem->text);
		if (elem->wbuffer)
			len += ft_strwlen(elem->wbuffer);
		if (elem->buffer && !(elem->value || (elem->type == 'c'
			&& elem->modifier.l) || elem->type == 'C'))
			len += ft_strlen(elem->buffer);
		if (elem->value || (elem->type == 'c' && elem->modifier.l)
		|| elem->type == 'C')
			len += ft_counter_unicode(elem);
		else if (elem->value)
			len += ft_wcharlen(elem->value);
		if (elem->null && (elem->type == 'c' || elem->type == 'C'))
			len++;
		elem = elem->next;
	}
	return (len);
}
