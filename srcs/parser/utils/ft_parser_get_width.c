/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_get_width.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 18:21:43 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/22 16:03:28 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_utils_parser.h"

int		ft_parser_get_width(char *reg)
{
	int		i;
	int 	res;
    int     len;
    char    *str;

    i = 0;
    len = 0;
    while (reg[i] != '.' && reg[i++] != '\0')
        len++;
    i = 0;
    if (len <= 1)
        return (-1);
    str = ft_strnew(len);
    while (len--)
    {
        str[i] = reg[i];
        i++;
    }
    while (*str <= 47 || *str >= 58)
        str++;
    res = ft_atoi(str);
	return ((!res) ? -1 : res);
}