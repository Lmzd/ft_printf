/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 18:12:57 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/06 03:42:35 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_formatter(t_data *list, va_list ap)
{
	t_data	*curr;

	curr = list;
	while (curr)
	{
		if (ft_strhas_char(TYPES, curr->type))
			ft_format_router(curr, ap);
		else
			curr->type = '\0';
		curr = curr->next;
	}
}
