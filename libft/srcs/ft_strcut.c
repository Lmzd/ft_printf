/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 22:48:41 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/05/10 13:41:50 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(char **src, int c)
{
	int		len;
	int		i;
	char	*cut;
	
	i = 0;
	len = 0;
	while ((*src)[i++] != c)
		len++;
	if (!(cut = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	i = 0;
	while (i < len && **src != '\0')
	{
		cut[i] = **src;
		(*src)++;
		i++;
	}
	cut[len] = '\0';
	return (cut);
}
