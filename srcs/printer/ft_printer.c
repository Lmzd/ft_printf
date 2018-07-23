/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 13:33:57 by pblouin           #+#    #+#             */
/*   Updated: 2018/07/23 19:51:07 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void    ft_print_null_bite(t_data *elem, int len)
{
    if (!elem->flags.dash)
    {
        write(1, elem->buffer, len);
        write(1, "\0", 1);
        return ;
    } 
        write(1, "\0", 1);
        write(1, elem->buffer, len);
}

int 	ft_printer (t_data *elem)
{
    int     len;
    int     total;
    int     null_bite;

	if (!elem)
		exit (0);
    len = 0;
    total = 0;
	while (elem)
	{
        if (elem->text)
        {
            len = ft_strlen(elem->text);
            total += len;
            write(1, elem->text, len);
        }
        if (elem->null
            && (elem->type == 'c' || elem->type == 'C'))
        {
            len = ft_strlen(elem->buffer);
            total += len + 1;
            ft_print_null_bite(elem, len);
        }
		else if (elem->buffer)
        {
            len = ft_strlen(elem->buffer);
            total += len;
            write(1, elem->buffer, len);
        }
		elem = elem->next;
	}
    return (total + 1);
}