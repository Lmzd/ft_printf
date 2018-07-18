/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_print_list_elem.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 12:16:00 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/18 13:51:41 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_utils_test.h"

void    ft_test_print_list_elem(t_data *elem)
{
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Type      : %c\n", elem->type);
    printf("Space     : %d\n", elem->flags.spaces);
    printf("Hash      : %d\n", elem->flags.hashtag);
    printf("Zero      : %d\n", elem->flags.zero);
    printf("Plus      : %d\n", elem->flags.plus);
    printf("Dash      : %d\n", elem->flags.dash);
    printf("Width     : %d\n", elem->width);
    printf("Precision : %d\n", elem->precision);
    printf("______________________________________\n\n");
}