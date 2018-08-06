/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_list.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 20:00:35 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/06 06:27:21 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_LIST_H
# define FT_UTILS_LIST_H

# include "./ft_printf.h"

void	ft_list_append(t_data **lst, t_data *new);
t_data	*ft_list_create_data_elem();
void	ft_init_values(t_data *elem);

#endif
