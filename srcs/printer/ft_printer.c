/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 13:33:57 by pblouin           #+#    #+#             */
/*   Updated: 2018/07/21 22:17:57 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int 	ft_printer (t_data *data)
{
    char    *res;
    int     len;
    t_data  *begin;

    begin = data;
	/* error handlin */
    len = 0;
	if (!data)
		exit (0);
	while (data)
	{
        if (data->text)
            len += ft_strlen(data->text);
		if (data->buffer)
            len += ft_strlen(data->buffer);
		data = data->next;
	}
    res = ft_strnew(len);
    data = begin;
    while (data)
	{
        if (data->text)
            ft_strcat(res, data->text);
		if (data->buffer)
            ft_strcat(res, data->buffer);
		data = data->next;
	}
    if (res)
        write(1, res, ft_strlen(res));
    return (ft_strlen(res) + 1);
}