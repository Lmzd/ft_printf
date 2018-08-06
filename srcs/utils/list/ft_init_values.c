/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 03:17:07 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/06 07:27:21 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

void	ft_init_values(t_data *elem)
{
	elem->buffer = NULL;
	elem->value = L'\0';
	elem->wbuffer = NULL;
	elem->null = 0;
	elem->wmalloc = 0;
}
