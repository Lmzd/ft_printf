/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatters.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 08:06:42 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/06 03:40:13 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FORMATTERS_H
# define FT_FORMATTERS_H

/*
** ALL RECIPES
*/

void	ft_format_int(t_data *data, va_list ap);
void	ft_format_u_int(t_data *data, va_list ap);
void	ft_format_hex(t_data *elem, va_list ap);
void	ft_format_char(t_data *elem, va_list ap);
void	ft_format_str(t_data *elem, va_list ap);
void	ft_format_percent(t_data *elem, va_list ap);

#endif
