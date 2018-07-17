/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_get_precision.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 17:42:46 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/17 17:42:58 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_parser_get_precision(char *regex)
{
	int 	i;
	int		j;
	int		len;
	char	*res;

	i = 0;
	len = 0;
	while (regex[i] != '.')
		i++;
	i++;
	while (regex[i] >= 48 && regex[i++] <= 59)
		len++;
	if (!(res = (char*)malloc(sizeof(char) * len + 1)))
		return (0);
	i = 0;
	while (regex[i] != '.')
		i++;
	i++;
	j = 0;
	while (regex[i] >= 48 && regex[i] <= 59)
		res[j++] = regex[i++];
	res[j] = '\0';
	return (ft_atoi(res));
}