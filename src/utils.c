/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:03:06 by mpascual          #+#    #+#             */
/*   Updated: 2020/09/15 19:27:11 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int             mod_putchar(char c)
{
    struct variables    var;
    
    if (c == '%' || c == '\\')
        return (0);
    else
    {
        putchar(c);
        var.printed_chars++;
        return (1);
    }
}

void            put_scape(char c)
{
    struct variables var;

    if (c == 'n')
        write(1, "\n", 1);
    else if (c == '%')
        var.printed_chars += ft_putchar('%');
    else if (c == 't')
        write(1, "\t", 1);
    else
    {
        ft_putstr("Error\nInvalid scape character");
        var.error = TRUE;
    }        
}

/*
unsigned int    get_number(char *str)
{
}
*/

/*
** ft_itohex requires a boolean parameter to specify if the alphabetic
** characters of the hex number are mayus
*/

int             ft_itohex(unsigned int nb, bool  mayus)
{
    unsigned int   num;
    unsigned int    l;
    int             a;

    a = mayus ? 55 : 87;
    num = nb;
    l = 0;
    if (num < 0)
    {
        ft_putchar('-');
        l++;
        num *= -1;
    }
    else if (num >= 16)
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