/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_print_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 10:04:41 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/02 07:59:42 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_utils_test.h"

void	ft_test_print_list(t_data **lst)
{
	t_data	*curr;

	curr = *lst;
	while (curr)
	{
		ft_test_print_list_elem(curr);
		curr = curr->next;
	}
}
