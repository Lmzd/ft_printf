/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 20:38:55 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/05/10 17:14:58 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_printf(const char *format, ...);
#include <stdio.h>

int 	main(int ac, char **av)
{
	ft_printf("je m'appelle % 8.4hhs et je suis a %+x et tout va bien %#d","Louis", 42, 21);
}	
