/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_precison_width_handler.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 18:50:24 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/07 07:04:35 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/libftprintf.h"

void	ft_format_precison_width_handler_helper(t_data *elem, char *str)
{
	char	*res;
	char	*buf;

	if (elem->neg && (elem->width < elem->precision))
	{
		res = ft_strjoin(str, elem->buffer);
		free(elem->buffer);
		elem->buffer = ft_strjoin("-", res);
	}
	else
	{
		buf = ft_strdup(elem->buffer);
		free(elem->buffer);
		elem->buffer = ft_strjoin(str, buf);
		free(buf);
	}
}

void	ft_format_precison_no_width(t_data *elem)
{
	char	*str;

	if (elem->neg)
	{
		str = elem->buffer;
		elem->buffer = ft_strjoin("-", str);
		free(str);
	}
}

void	ft_format_precison_width_handler(t_data *elem)
{
	int		len;
	int		range;
	char	*str;
	char	*buf;

	len = ft_strlen(elem->buffer);
	if (elem->width <= len)
	{
		ft_format_precison_no_width(elem);
		return ;
	}
	if (elem->neg && (elem->width >= elem->precision))
	{
		buf = ft_strdup(elem->buffer);
		free(elem->buffer);
		elem->buffer = ft_strjoin("-", buf);
		free(buf);
	}
	str = ft_strnew(elem->width - len);
	range = elem->width - len - elem->neg;
	while (range--)
		str[range] = ' ';
	ft_format_precison_width_handler_helper(elem, str);
	free(str);
}
