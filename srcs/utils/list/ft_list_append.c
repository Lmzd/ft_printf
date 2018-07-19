/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_append.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pblouin <pblouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 17:46:29 by lmazeaud          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/07/19 17:03:15 by lmazeaud         ###   ########.fr       */
=======
/*   Updated: 2018/07/18 11:52:15 by pblouin          ###   ########.fr       */
>>>>>>> c2620537f1ceb5615eabf7797800ab4fcf215aa5
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
		*lst = new;
		new->next = NULL;
	}
}
