/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pblouin <pblouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 20:38:55 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/21 13:47:43 by pblouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_printf(const char *format, ...);
#include <stdio.h>
#include "../includes/ft_printf.h"


int 	main(int ac, char **av)
{
	//ft_printf("je m'appelle %00000008.4hhs et je suis a %+6x et tout va bien %#42d","Louis", 42, 21);
	ft_printf("test des d <%+8d>\n", 2);
	printf("test des d <%+8d>\n", 2);
	printf("test des d <%+8d>\n", 1000042);
	printf("test des d <%+08d>\n", 0000042);
	printf("test des d <%+08d>\n", 0000042);
	ft_printf("test des d <%+8d>\n", 12000042);
	printf("test des d <%+8d>\n", 1000000042);
	printf("test des d <%+8ld>\n", (long)1000000000042);
	//printf("je m'appelle fjeirohgoehg %s", "coucou");
	// test_format_01();
}	
// test des d <      42>%