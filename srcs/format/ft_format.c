/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 18:12:57 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/11 19:04:36 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

int		ft_formatter(t_data *list, va_list ap)
{
	t_data	*elem;
	int		ret;
    char    *buf;

	elem = list;
	ret = 1;
	while (elem)
	{
		if (ft_strhas_char(TYPES, elem->type))
			ft_format_router(elem, ap);
		else
        {
			elem->type = '\0';
            if (elem->width > 0 && elem->flags.zero && !elem->flags.dash)
                elem->buffer = ft_fillit('0', elem->width - 1);
            else if (elem->width > 0 && !elem->flags.zero && !elem->flags.dash)
                elem->buffer = ft_fillit(' ', elem->width - 1);
        }
		if (elem->error)
		{
			ret = -1;
			break ;
		}
		elem = elem->next;
	}
	return (ret);
}
