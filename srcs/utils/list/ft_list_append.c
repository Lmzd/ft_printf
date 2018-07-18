/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_append.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:srcs/utils/list/ft_append.c
/*   Created: 2018/07/17 17:46:29 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/17 18:00:30 by pblouin          ###   ########.fr       */
=======
/*   Created: 2018/07/17 18:20:50 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/17 20:05:30 by lmazeaud         ###   ########.fr       */
>>>>>>> 4e81311eb2674aa930b70cf7c234f98325d69d9b:srcs/utils/list/ft_list_append.c
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

/*
**	name: ft_list_append
**
**  desc: Append a new element to the end of a linked list
**  input:
**      lst: a pointer to the head of the list
**      new: new list element
**  return: nothing (we use a pointer of pointer to edit the lst directly)
*/
void	ft_list_append(t_data **lst, t_data *new)
{
	t_data	*list_tmp;

	list_tmp = *lst;
	if (list_tmp)
	{
		while (list_tmp->next)
			list_tmp = list_tmp->next;
		list_tmp->next = new;
		new->next = NULL;
	}
	else
	{
		list_tmp = new;
		new->next = NULL;
	}
}
