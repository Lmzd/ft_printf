/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_wstr_precision_handler.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 17:11:45 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/06 08:38:17 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/ft_printf.h"

int		ft_format_wstr_cut_precision_helper(t_data *elem, wchar_t *str,
	int preci, int i)
{
	if ((int)ft_wcharlen(elem->wbuffer[i]) <= preci)
	{
		str[i] = elem->wbuffer[i];
		preci -= ft_wcharlen(str[i]);
		return (1);
	}
	else
	{
		str[i] = L'\0';
		return (0);
	}
}

void	ft_format_wstr_cut_precision(t_data *elem, int preci)
{
	int		i;
	wchar_t	*str;

	if (!(str = (wchar_t*)malloc(sizeof(wchar_t) * preci + 1)))
		return ;
	i = 0;
	while (i < preci + 1)
		str[i++] = L'\0';
	i = -1;
	while (i++ <= preci)
	{
		if ((int)ft_wcharlen(elem->wbuffer[i]) <= preci)
		{
			str[i] = elem->wbuffer[i];
			preci -= ft_wcharlen(str[i]);
		}
		else
		{
			str[i] = L'\0';
			break ;
		}
	}
	(elem->wmalloc) ? free(elem->wbuffer) : ft_strlen(elem->text);
	elem->wmalloc = 1;
	elem->wbuffer = str;
}

void	ft_format_wstr_precision_handler(t_data *elem)
{
	int		len;
	int		preci;

	len = ft_strwlen(elem->wbuffer);
	preci = elem->precision;
	elem->wbuffer = (!preci) ? L"" : elem->wbuffer;
	if (preci < len)
		ft_format_wstr_cut_precision(elem, preci);
}
