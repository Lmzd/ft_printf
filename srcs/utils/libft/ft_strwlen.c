/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 19:24:12 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/22 18:58:51 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libftprintf.h"

int		ft_strwlen(wchar_t *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (ft_wcharlen(str[i]) > 0)
			j += ft_wcharlen(str[i]);
		else
			return (-1);
		i++;
	}
	return (j);
}
