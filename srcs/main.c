/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 20:38:55 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/19 17:09:10 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_printf(const char *format, ...);
#include <stdio.h>
#include "../includes/ft_printf.h"


int 	main(int ac, char **av)
{
	//ft_printf("je m'appelle %00000008.4hhs et je suis a %+6x et tout va bien %#42d","Louis", 42, 21);
	ft_printf("test des d <%d>", 42);
	//printf("je m'appelle fjeirohgoehg %s", "coucou");
	test_format_01();
}	
