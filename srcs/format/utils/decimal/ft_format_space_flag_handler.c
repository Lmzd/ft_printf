/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_space_flag_handler.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 18:36:51 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/05 02:42:04 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/ft_printf.h"

void	ft_format_space_flag_handler(t_data *elem)
{
	int		len;
	char	*buf;

	if (elem->flags.plus || elem->type == 'c' || elem->type == 'C'
		|| elem->type == 'u' || elem->type == 'U')
		return ;
	if (!elem->flags.spaces || elem->neg)
		return ;
	len = ft_strlen(elem->buffer);
	if (elem->width < len)
	{
		buf = ft_strdup(elem->buffer);
		free(elem->buffer);
		elem->buffer = ft_strjoin(" ", buf);
		free(buf);
	}
	else
		elem->buffer[0] = ' ';
}
