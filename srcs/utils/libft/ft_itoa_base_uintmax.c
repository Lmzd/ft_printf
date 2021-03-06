/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_uintmax.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 00:19:42 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/10 13:04:22 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libftprintf.h"

static int		ft_nb_len_base(uintmax_t n, int base)
{
	int len;

	len = 1;
	while (n /= base)
		len++;
	return (len);
}

char			*ft_itoa_base_uintmax(uintmax_t n, int base, t_data *elem)
{
	int				nb_len;
	char			*res;
	static char		str_charset[] = "0123456789abcdef";

	if (n == ULONG_MAX && (elem->type == 'U'
		|| (elem->type == 'u' && elem->modifier.l)))
		return (ft_strdup("18446744073709551615"));
	nb_len = ft_nb_len_base(n, base);
	if (!(res = ft_strnew(nb_len)))
		return (NULL);
	while (nb_len > 0)
	{
		res[nb_len-- - 1] = str_charset[(n % base)];
		n /= base;
	}
	return (res);
}
