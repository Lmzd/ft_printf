/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_wstr_precision_handler.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 17:11:45 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/08 22:16:39 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/libftprintf.h"

void	ft_format_wstr_cut_precision_helper(t_data *elem, wchar_t *str,
	int preci)
{
	int		i;
	int		len;

	i = 0;
	while (preci > 0)
	{
		if ((int)ft_wcharlen(elem->wbuffer[i]) <= preci)
		{
			str[i] = elem->wbuffer[i];
		}
		else
		{
			str[i] = L'\0';
			break ;
		}
		len = ft_wcharlen(str[i]);
		i++;
		preci -= len;
	}
}

void	ft_format_wstr_cut_precision(t_data *elem, int preci)
{
	wchar_t	*str;

	if (!(str = (wchar_t*)malloc(sizeof(wchar_t) * preci + 1)))
		return ;
	ft_wbzero(str, preci + 1);
	ft_format_wstr_cut_precision_helper(elem, str, preci);
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
