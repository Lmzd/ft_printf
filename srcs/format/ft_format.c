/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 18:12:57 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/08 08:41:55 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

int		ft_formatter(t_data *list, va_list ap)
{
	t_data	*curr;
	int		ret;

	curr = list;
	ret = 1;
	while (curr)
	{
		if (ft_strhas_char(TYPES, curr->type))
			ft_format_router(curr, ap);
		else
			curr->type = '\0';
		if (curr->error)
		{
			ret = -1;
			break ;
		}
		curr = curr->next;
	}
	return (ret);
}
