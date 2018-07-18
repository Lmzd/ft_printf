/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_create_data_elem.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 11:25:15 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/18 13:32:39 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

t_data		*ft_list_create_data_elem()
{
	t_data	*curr;

	if (!(curr = (t_data*)malloc(sizeof(t_data))))
		return (NULL);
	curr->next = NULL;
	return(curr);
}
