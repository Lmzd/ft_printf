/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_print_list_elem.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 12:16:00 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/02 08:39:52 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_utils_test.h"

void	ft_test_print_list_elem(t_data *elem)
{
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Text    : %s\n", elem->text);
	printf("Expres  : %s\n", elem->expression);
	printf("            ~~~~~~~~~~~~                  \n");
	printf("Type    : %c\n", elem->type);
	printf("Width   : %d\n", elem->width);
	printf("Precis  : %d\n", elem->precision);
	printf("            ~~~~~~~~~~~~                  \n");
	printf("Space   : %d\n", elem->flags.spaces);
	printf("Hash    : %d\n", elem->flags.hash);
	printf("Zero    : %d\n", elem->flags.zero);
	printf("Plus    : %d\n", elem->flags.plus);
	printf("Dash    : %d\n", elem->flags.dash);
	printf("            ~~~~~~~~~~~~                 \n");
	printf("h       : %d\n", elem->modifier.h);
	printf("hh      : %d\n", elem->modifier.hh);
	printf("l       : %d\n", elem->modifier.l);
	printf("ll      : %d\n", elem->modifier.ll);
	printf("j       : %d\n", elem->modifier.j);
	printf("z       : %d\n", elem->modifier.z);
	printf("______________________________________\n\n");
}
