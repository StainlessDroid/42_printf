/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:03:06 by mpascual          #+#    #+#             */
/*   Updated: 2020/09/28 17:52:32 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void init_flags(s_var *var)
{
	var->printed_chars = 0;
	var->precision = 0;
	var->width = 0;
	var->minus = FALSE;
	var->zero = FALSE;
}

int		is_type(char c)
{
	if (c == 'c' ||  c == 's' || c == 'i' || c == 'd' || c == 'u' || c == 'x'
		|| c == 'X' || c == 'p')
		return (1);
	else
		return (0);
}

int    get_number(const char *str)
{
    int        i;
    int        len;
    char       *number;

    i = 0;
    len = 0;
    while (ft_isdigit(str[len]))
        len++;
    if (!(number = malloc(len + 1)))
        return (-1);
    i = 0;
    while (len > 0)
    {
        number[i] = str[i];
        i++;
        len--;
    }
    number[i] = '\0';
    return (ft_atoi(number));
}

/*
** ft_itohex requires a boolean parameter to specify if the alphabetic
** characters of the hex number are mayus
*/

int    ft_itohex(unsigned int nb, bool  mayus)
{
    unsigned int   num;
    unsigned int    l;
    int             a;

    a = mayus ? 55 : 87;
    num = nb;
    l = 0;
    if (num >= 16)
    {
        ft_itohex(num / 16, mayus);
        ft_putchar(num % 16 + (num % 16 >= 9 ? a : '0'));
        l++;
    }
    else
    {
        ft_putchar(num + (num % 16 >= 9 ? a : '0'));
        l++;
    }
    return (l);
}
