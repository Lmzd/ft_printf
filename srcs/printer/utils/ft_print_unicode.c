/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unicode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:19:41 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/07 07:04:35 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libftprintf.h"

void	ft_print_unicode(t_data *elem)
{
	int	len;

	len = ft_strlen(elem->buffer);
	if (!elem->flags.dash)
	{
		write(1, elem->buffer, len);
		ft_putwchar(elem->value);
		return ;
	}
	ft_putwchar(elem->value);
	write(1, elem->buffer, len);
}
