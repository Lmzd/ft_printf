/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 13:33:57 by pblouin           #+#    #+#             */
/*   Updated: 2018/07/21 13:14:54 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_printer (t_data *data)
{
	/* error handlin */
	if (!data)
		exit (0);
	while (data)
	{
        if (data->text)
            write(1, data->text, ft_strlen(data->text));
		if (data->buffer)
            write(1, data->buffer, ft_strlen(data->buffer));
		data = data->next;
	}
}