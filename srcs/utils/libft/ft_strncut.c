/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 12:32:26 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/07 07:43:49 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libftprintf.h"

char	*ft_strncut(char **src, size_t n)
{
	size_t	i;
	char	*cut;

	i = 0;
	cut = ft_strnew(n);
	while (i < n && **src != '\0')
	{
		cut[i] = **src;
		(*src)++;
		i++;
	} 
	return (cut);
}
