/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 18:56:34 by mpascual          #+#    #+#             */
/*   Updated: 2020/10/01 21:56:26 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../header.h"

int				i1 = 11074;
int				i2 = -4004;
unsigned int	ui1 = 69047;
unsigned int	ui2 = 8;
unsigned long	ul = 694201170000;
char			c1 = 'p';
char			c2 = 'F';
char			*s1 = "Lorem ipsum dolor sit amet";
char			*s2 = "caca¡'º12º208‚?<+`ç¨Ç´^\\@@'&%#||=0)(";
int				*ptr = &i1;

int     main(void)
{
  //printf("\033[0;32m");   // Set printf color output to GREEN
  printf("i1=%.7d\n", i1);
  printf("i2=%.7d\n", i2);
  //printf("\033[0m");      // Set printf color back to default

  ft_printf("i1=%.7d\n", i1);
  ft_printf("i2=%.7d\n", i2);
	//system ("leaks Test_ex");

	return (0);
}
