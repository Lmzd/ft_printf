/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_structure.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 13:30:13 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/06 08:16:20 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

void	ft_free_structure_buffer(t_data *elem)
{
	if ((elem->type == 's') && elem->wmalloc)
		free(elem->buffer);
	else if ((elem->type != 's' && elem->type != 'S')
		&& elem->null && elem->precision != 0)
		free(elem->buffer);
	else if (elem->buffer && !elem->null && elem->type != 's')
		free(elem->buffer);
	else if ((elem->type == 's' || elem->type == 'S') && elem->null)
		free(elem->buffer);
	else if ((elem->type == 'x' || elem->type == 'X') && elem->null
		&& elem->precision == 0 && elem->flags.dash)
		free(elem->buffer);
	else if (elem->type == 'p' && elem->precision == 0 && elem->null)
		free(elem->buffer);
	else if (!elem->precision && !elem->flags.hash
		&& (elem->type == 'o' || elem->type == 'O') && elem->width == -1)
		free(elem->buffer);
}

void	ft_free_structure(t_data **begin)
{
	t_data *tmp;
	t_data *elem;

	elem = *begin;
	while (elem)
	{
		if (elem->text)
			free(elem->text);
		if (elem->expression)
			free(elem->expression);
		if (elem->wbuffer && elem->wmalloc)
			free(elem->wbuffer);
		else
			ft_free_structure_buffer(elem);
		tmp = elem;
		elem = elem->next;
		free(tmp);
	}
}
