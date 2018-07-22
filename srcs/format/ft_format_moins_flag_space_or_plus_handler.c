/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_moins_flag_space_or_plus_handler.        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 20:29:56 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/22 22:01:05 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void    ft_format_moins_flag_space_or_plus_handler(t_data *elem)
{
    char extension;
    char *buf;
    char *str;
    int len;
    int width;
    
    extension = (elem->flags.spaces) ? ' '  : '+';
    width = elem->width;
    if (!elem->flags.spaces && !elem->flags.plus)
        return ;
    buf = ft_strdup(elem->buffer);
    len = ft_strlen(buf);
    str = ft_strnew(width);
    if (!elem->neg)
    {
        str[0] = extension;
        ft_strcat(str, buf);
        str[width] = '\0';
        elem->buffer = ft_strdup(str);
    }
    free(str);
    free(buf);
}