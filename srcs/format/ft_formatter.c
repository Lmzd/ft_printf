/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pblouin <pblouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 18:12:57 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/19 20:47:53 by pblouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_data  *ft_formatter(t_data *list, va_list ap)
{
    t_data *curr;
	
	curr = list;
	while (curr)
	{
		ft_format_router(curr, ap);
		curr = curr->next;
	}
}