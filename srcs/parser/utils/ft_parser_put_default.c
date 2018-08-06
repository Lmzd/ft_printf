/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_put_default.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 15:15:42 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/02 07:54:22 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

void	ft_parser_put_default(t_data *elem)
{
	elem->width = -1;
	elem->precision = -1;
	elem->expression = NULL;
	elem->type = 0;
	elem->buffer = NULL;
}
