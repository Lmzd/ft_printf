/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_regex_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 17:53:20 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/17 17:53:35 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Find the regex length
*/
int	ft_get_regex_len(char **src)
{
	int 			len;
	int 			i;
	int				j;
	
	i = 0;
	len = 0;
	while ((*src)[i] != '\0')
	{
		j = 0;
		while (TYPES[j] != '\0')
		{
			if ((*src)[i] == TYPES[j])
				return (++len);
			j++;
		}
		i++;
		len++;
	}
	return (len);
}
