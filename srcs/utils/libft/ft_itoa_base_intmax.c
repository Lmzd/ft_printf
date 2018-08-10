/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_intmax.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 00:19:42 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/10 15:08:54 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libftprintf.h"
#include <stdio.h>

static int		ft_nb_len_base(intmax_t n, int base)
{
	int len;

	len = 1;
	while (n /= base)
		len++;
	return (len);
}

char			*ft_itoa_base_intmax(intmax_t n, int base, t_data *elem)
{
	int				is_neg;
	int				nb_len;
	char			*res;
	static char		str_charset[] = "0123456789abcdef";

	if (n == LONG_MIN && (elem->type == 'D'
		|| ((elem->type == 'd' || elem->type == 'i')
		&& (elem->modifier.l || elem->modifier.ll || elem->modifier.j
		|| elem->modifier.z))))
		return (ft_strdup("9223372036854775808"));
	is_neg = (n < 0) ? 1 : 0;
	n = (n < 0) ? n * -1 : n;
	nb_len = ft_nb_len_base(n, base);
	res = ft_strnew(nb_len);
	nb_len += is_neg;
	while (nb_len > is_neg)
	{
		res[nb_len-- - 1] = str_charset[(n % base)];
		n /= base;
	}
	res[0] = (is_neg) ? '-' : res[0];
	return (res);
}
