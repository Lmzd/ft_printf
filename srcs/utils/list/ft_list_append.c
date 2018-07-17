/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_append.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 18:20:50 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/17 18:21:08 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	name: ft_list_append
**
**  desc: Append in a list a new element at the end of the linked list 
**  input: 
**      lst: begin of the data structure
**      new: new structure element
**  return: void
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
