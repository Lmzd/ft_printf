/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_moins_flag_space_or_plus_handler.        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 20:29:56 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/10 15:07:33 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/libftprintf.h"

void	ft_format_moins_flag_space_or_plus_handler(t_data *elem)
{
	char	*extension;
	char	*buf;
	int		len;
	int		width;

	width = elem->width;
	len = ft_strlen(elem->buffer);
	if (elem->type == 'c' || elem->type == 'C'
		|| elem->type == 'u' || elem->type == 'U')
		return ;
	if (!elem->flags.spaces && !elem->flags.plus)
		return ;
	extension = (elem->flags.spaces) ? ft_strdup(" ") : ft_strdup("+");
	if (!elem->neg)
	{
		buf = elem->buffer;
		elem->buffer = ft_strjoin(extension, buf);
		elem->buffer[len] = '\0';
		free(buf);
	}
	free(extension);
}
