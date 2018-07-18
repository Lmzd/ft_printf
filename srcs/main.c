/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 20:38:55 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/18 22:17:23 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_printf(const char *format, ...);
#include <stdio.h>

int 	main(int ac, char **av)
{
	ft_printf("je m'appelle %d, et je suis %s", 42, "coucou");
	printf("je m'appelle fjeirohgoehg %s", "coucou");
}	
