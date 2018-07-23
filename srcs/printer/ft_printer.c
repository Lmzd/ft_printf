/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 13:33:57 by pblouin           #+#    #+#             */
/*   Updated: 2018/07/23 23:11:12 by lmazeaud         ###   ########.fr       */
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

void    ft_print_unicode(t_data *elem)
{
    if (!elem->flags.dash)
    {
        ft_putwchar(elem->value);
        write(1, elem->buffer, ft_strlen(elem->buffer));
        return ;
    } 
        write(1, elem->buffer, ft_strlen(elem->buffer));
        ft_putwchar(elem->value);
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
        if (elem->value)
        {
            total += MB_CUR_MAX;
            ft_print_unicode(elem);
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