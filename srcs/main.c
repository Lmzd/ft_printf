/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pblouin <pblouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 20:38:55 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/22 19:58:41 by pblouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_printf(const char *format, ...);
#include <stdio.h>
#include "../includes/ft_printf.h"

void	check(char *s, intmax_t nbr)
{
	printf("%s,%jd,[", s, nbr);
	printf(s, nbr);
	printf("],[");
  fflush(stdout);
  ft_printf(s, nbr);
  printf("]\n");
}


int 	main(int ac, char **av)
{
  printf("expression,number,printf_result,ft_printf_result");
	// //ft_printf("je m'appelle %00000008.4hhs et je suis a %+6x et tout va bien %#42d","Louis", 42, 21);
	// // ft_printf("test des d <%+8d>\n", 12000042);
    // // ft_printf("test des d <%+8d>\n", -42);
    // // ft_printf("test des d <%+d>\n", -42);
   
    // // ft_printf("test des d <%+1d>\n", 42);
    // ft_printf("test des d <%-1d>\n", 42);
    // ft_printf("test des d <%+-8d>\n", 42);
    // printf("printf test des d <%1d>\n", 42);
    // printf("test des d <%+-8d>\n", 42);

    // printf("\nprintf value\n");
    // printf("test des d <%+8d>\n", 12000042);
    // printf("test des d <%+8d>\n", -42);
    // printf("test des d <%+d>\n", -42);
    // printf("test des d <%0+8d>\n", -42);
    // printf("test des d <%01d>\n", 42);
    // printf("% d\n", 42);	
	// //printf("je m'appelle fjeirohgoehg %s", "coucou");
	// // test_format_01();
    /* Verification des decimals, %i et %d */

  // ft_printf("%d\n", ft_printf("1chiffre 1 %d chiffre 2 %d\n", 42, -42));
  // printf("%d\n\n", printf("1chiffre 1 %d chiffre 2 %d\n\n", 42, -42));

  // ft_printf("%d\n", ft_printf("2chiffre 1 %   d chiffre 2 % d\n", 42, -42));
  // printf("%d\n\n", printf("2chiffre 1 %   d chiffre 2 % d\n\n", 42, -42));

  // ft_printf("%d\n", ft_printf("3chiffre 1 %12d chiffre 2 %12d\n", 42, -42));
  // printf("%d\n\n", printf("3chiffre 1 %12d chiffre 2 %12d\n\n", 42, -42));

  // ft_printf("%d\n", ft_printf("4chiffre 1 %-12d chiffre 2 %-12d\n", 42, -42));
  // printf("%d\n\n",     printf("4chiffre 1 %-12d chiffre 2 %-12d\n\n", 42, -42));

  // ft_printf("%d\n", ft_printf("5chiffre 1 %0d chiffre 2 %0d\n", 42, -42));
  // printf("%d\n\n", printf("5chiffre 1 %0d chiffre 2 %0d\n\n", 42, -42));

  // ft_printf("%d\n", ft_printf("6chiffre 1 %012d chiffre 2 %012d\n", 42, -42));
  // printf("%d\n\n", printf("6chiffre 1 %012d chiffre 2 %012d\n\n", 42, -42));

  // ft_printf("%d\n", ft_printf("7chiffre 1 %-012d chiffre 2 %012d\n", 42, -42));
  // printf("%d\n\n", printf("7chiffre 1 %-012d chiffre 2 %012d\n\n", 42, -42));

//   ft_printf("%d\n", ft_printf("8chiffre 1 %*d chiffre 2 %*d\n", 42, 6, 6, 6));
//   printf("%d\n\n", printf("8chiffre 1 %*d chiffre 2 %*d\n\n", 42, 6, 6, 6));

  // ft_printf("%d\n", ft_printf("9chiffre 1 %+d chiffre 2 %+d\n", 42, 6, -42, 6));
  // printf("%d\n\n", printf("9chiffre 1 %+d chiffre 2 %+d\n\n", 42, 6, -42, 6));

  // ft_printf("%d\n", ft_printf("10chiffre 1 %+12d chiffre 2 %+12d\n", 42, 6, -42, 6));
  // printf("%d\n\n", printf("10chiffre 1 %+12d chiffre 2 %+12d\n\n", 42, 6, -42, 6));

//   ft_printf("%d\n", ft_printf("11chiffre 1 %*12d chiffre 2 %*12d\n", 42, -6, 42, 6));
//   printf("%d\n\n", printf("11chiffre 1 %*12d chiffre 2 %*12d\n\n", 42, -6, 42, 6));
  
//   ft_printf("%d\n", ft_printf("12chiffre 1 %-+5d chiffre 2 %-+5d\n", 42, -42));
//   printf("%d\n\n", printf("12chiffre 1 %-+5d chiffre 2 %-+5d\n\n", 42, -42));  

//   ft_printf("%d\n", ft_printf("13chiffre 1 %-+05d chiffre 2 %-+05d\n", 42, -42));
//   printf("%d\n\n", printf("13chiffre 1 %-+05d chiffre 2 %-+05d\n\n", 42, -42));

//   ft_printf("%d\n", ft_printf("14chiffre 1 %+-5d chiffre 2 %+-5d\n", 42, -42));
//   printf("%d\n\n", printf("14chiffre 1 %+-5d chiffre 2 %+-5d\n\n", 42, -42));

//   ft_printf("%d\n", ft_printf("15 chiffre 1 %.d chiffre 2 %.d\n", 42, -42));
//    fflush(stdout);
//   printf("%d\n\n", printf("15 chiffre 1 %.d chiffre 2 %.d\n\n", 42, -42));
//    fflush(stdout);

  ft_printf("%d\n", ft_printf("16chiffre 1 %12.6d chiffre 2 %12.6d\n", 42, -42));
  printf("%d\n\n", printf("16chiffre 1 %12.6d chiffre 2 %12.6d\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("16chiffre 1 %-12.6d chiffre 2 %-12.6d\n", 42, -42));
  printf("%d\n\n", printf("16chiffre 1 %-12.6d chiffre 2 %-12.6d\n\n", 42, -42));
  // ft_printf("%d\n", ft_printf("15 chiffre 1 %.d chiffre 2 %.d\n", 42, -42));
  //  fflush(stdout);
  // printf("%d\n\n", printf("15 chiffre 1 %.d chiffre 2 %.d\n\n", 42, -42));
  //  fflush(stdout);

  // ft_printf("%d\n", ft_printf("16 chiffre 1 %.6d chiffre 2 %.6d\n", 42, -42));
  //  fflush(stdout);
  // printf("%d\n\n", printf("16 chiffre 1 %.6d chiffre 2 %.6d\n\n", 42, -42));
  //  fflush(stdout);

  printf("%lu\n", sizeof(char));
  printf("%lu\n", sizeof(short));
  printf("%lu\n", sizeof(int));
  printf("%lu\n", sizeof(long int));
  printf("%lu\n", sizeof(long long int));
  printf("%lu\n", sizeof(intmax_t));
  printf("%lu\n", sizeof(size_t));

  printf("==== TEST HEX ====\n");

  check("%x", 512);
	check("%x", 18);
	check("%x", -512);
	check("%x", -18);
	check("%x", 0);
	check("%.2x", 0);
	check("%.3x", 0);
	check("%.3x", 0);
	check("%.2x", 10);
	check("%.3x", 10);
	check("%.3x", 10);
	check("%.2x", 0);
	check("%#x", 0);
	check("%#x", 1);
	check("%#x", -1);
	check("%#x", 16);
	check("%#x", 455);
	check("%#x", -455);

}
