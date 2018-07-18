/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 22:48:41 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/18 16:27:25 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(char **src, int c)
{
	int		len;
	int		i;
	char	*cut;
    int     eol;
	
	i = 0;
	len = 0;
    eol = 0;
    (void)c;
	while ((*src)[i] != '\0' && (*src)[i++] != c)
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
