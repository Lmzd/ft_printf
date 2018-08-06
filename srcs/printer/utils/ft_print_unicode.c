/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unicode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:19:41 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/04 05:16:14 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

void	ft_print_unicode(t_data *elem)
{
	if (!elem->flags.dash)
	{
		write(1, elem->buffer, ft_strlen(elem->buffer) - 1);
		ft_putwchar(elem->value);
		return ;
	}
	ft_putwchar(elem->value);
	write(1, elem->buffer, ft_strlen(elem->buffer) - 1);
}
