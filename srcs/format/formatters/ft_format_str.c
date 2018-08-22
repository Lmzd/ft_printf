/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 14:13:25 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/22 18:03:11 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libftprintf.h"

void	ft_format_str_check(t_data *elem)
{
	int		i;

	i = 0;
	if (MB_CUR_MAX == 1)
	{
		while (elem->wbuffer[i] != '\0')
		{
			if ((elem->wbuffer[i] > 55295 && elem->wbuffer[i] < 57344)
				|| elem->wbuffer[i] > 1114111 || elem->wbuffer[i] < 0)
			{
				elem->error = 1;
				elem->wbuffer = NULL;
				break ;
			}
			i++;
		}
	}
}

void	ft_format_str_modifier(t_data *elem, va_list ap)
{
	char	*value;
	wchar_t *val;

	elem->neg = 0;
	elem->modifier.l = (elem->modifier.ll) ? 0 : elem->modifier.l;
	if (elem->type == 'S'
		|| (elem->type == 's' && elem->modifier.l && !elem->modifier.ll))
	{
		val = va_arg(ap, wchar_t *);
		elem->null = (!val) ? 1 : 0;
		elem->buffer = (elem->null) ? ft_strdup("(null)") : NULL;
		elem->wmalloc = (elem->null) ? 1 : 0;
		elem->wbuffer = val;
		ft_format_str_check(elem);
	}
	else if (elem->type == 's')
	{
		value = va_arg(ap, char *);
		elem->null = (!value) ? 1 : 0;
		elem->buffer = (elem->null) ? ft_strdup("(null)") : value;
		elem->wmalloc = (elem->null) ? 1 : 0;
	}
}

void	ft_format_str(t_data *elem, va_list ap)
{
	ft_init_values(elem);
	ft_format_str_modifier(elem, ap);
	if (elem->wbuffer)
		ft_format_wstr_flags(elem);
	else if (elem->buffer)
		ft_format_str_flags(elem);
}
