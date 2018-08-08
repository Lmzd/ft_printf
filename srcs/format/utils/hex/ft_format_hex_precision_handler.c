/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_hex_precision_handler.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 18:50:14 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/07 07:04:35 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/libftprintf.h"

void	ft_format_hex_precision_helper(t_data *elem, char *prefix, char *str)
{
	int len;
	int preci;

	len = ft_strlen(elem->buffer);
	preci = elem->precision;
	if (elem->precision >= len)
	{
		while (len--)
			str[--preci] = elem->buffer[len];
		while (preci--)
			str[preci] = '0';
		free(elem->buffer);
		elem->buffer = (elem->flags.hash || elem->type == 'p')
			? ft_strjoin(prefix, str) : ft_strdup(str);
	}
}

void	ft_format_hex_precision_free(char *s1, char *s2)
{
	free(s1);
	free(s2);
}

void	ft_format_hex_precision_handler(t_data *elem)
{
	int		len;
	char	*str;
	int		preci;
	char	*prefix;
	char	*buf;

	prefix = (elem->type == 'O' || elem->type == 'o')
		? ft_strdup("0") : ft_strdup("0x");
	len = ft_strlen(elem->buffer);
	preci = elem->precision;
	str = ft_strnew(preci);
	if (preci <= len && (elem->flags.hash || elem->type == 'p'))
	{
		if (elem->null && preci == 0)
		{
			free(elem->buffer);
			elem->buffer = ft_strdup("");
		}
		buf = elem->buffer;
		elem->buffer = ft_strjoin(prefix, buf);
		free(buf);
	}
	else
		ft_format_hex_precision_helper(elem, prefix, str);
	ft_format_hex_precision_free(prefix, str);
}
