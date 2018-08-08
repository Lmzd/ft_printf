/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_create_data_elem.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 11:25:15 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/07 07:04:35 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libftprintf.h"

t_data		*ft_list_create_data_elem(void)
{
	t_data	*curr;

	if (!(curr = (t_data*)malloc(sizeof(t_data))))
		return (NULL);
	curr->flags.dash = 0;
	curr->flags.zero = 0;
	curr->flags.spaces = 0;
	curr->flags.plus = 0;
	curr->flags.hash = 0;
	curr->modifier.h = 0;
	curr->modifier.hh = 0;
	curr->modifier.l = 0;
	curr->modifier.ll = 0;
	curr->modifier.j = 0;
	curr->modifier.z = 0;
	curr->precision = -1;
	curr->width = -1;
	curr->neg = 0;
	curr->type = '\0';
	curr->text = NULL;
	curr->expression = NULL;
	ft_init_values(curr);
	curr->next = NULL;
	return (curr);
}
