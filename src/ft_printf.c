/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:17:37 by mpascual          #+#    #+#             */
/*   Updated: 2020/10/06 20:32:15 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int				get_precision(const char *format, va_list arg, t_var *var)
{
	int		i;

	i = 1;
	if (*format == '*')
	{
		var->precision = va_arg(arg, int);
		i++;
	}
	else
	{
		var->precision = get_number(format);
		i += (*format == '0') ? (ft_nbrlen(var->precision, 10) + 1) :
		ft_nbrlen(var->precision, 10);
	}
	var->is_precision = TRUE;
	if (var->precision < 0)
		var->precision *= -1;
	return (i);
}

unsigned int	digit_flags(const char *format, t_var *var)
{
	unsigned int	i;

	i = 0;
	while (*format && ft_isdigit(*format))
	{
		if (*format == '0')
		{
			if (!var->minus)
				var->zero = TRUE;
			format++;
			i++;
		}
		else
		{
			var->width = get_number(format++);
			i += ft_nbrlen(var->width, 10);
			break ;
		}
	}
	return (i);
}

unsigned int	find_flags(const char *format, va_list arg, t_var *var)
{
	unsigned int	i;

	i = 0;
	while (!is_type(*format))
	{
		if (*format == '-')
			var->format_pos += minus(var);
		else if (*format == '*')
			var->format_pos += star(var, arg);
		else if (*format == '.')
			var->format_pos += get_precision(++format, arg, var);
		else if (ft_isdigit(*format))
			var->format_pos += digit_flags(format, var);
		else
			break ;
		format += var->format_pos;
		i += var->format_pos;
		var->format_pos = 0;
	}
	return (i);
}

void			check_type(const char c, va_list arg, t_var *var)
{
	if (c == 'c')
		var->printed_chars += print_c(va_arg(arg, int), var);
	else if (c == 's')
		var->printed_chars += print_s(va_arg(arg, char*), var);
	else if (c == 'd' || c == 'i')
		var->printed_chars += print_di(va_arg(arg, int), var);
	else if (c == 'u')
		var->printed_chars += print_u(va_arg(arg, unsigned int), var);
	else if (c == 'p')
		var->printed_chars += print_p(va_arg(arg, unsigned long), var);
	else if (c == 'x')
		var->printed_chars += print_x(va_arg(arg, unsigned int), FALSE, var);
	else if (c == 'X')
		var->printed_chars += print_x(va_arg(arg, unsigned int), TRUE, var);
	else if (c == '%')
		var->printed_chars += print_c('%', var);
}

int				ft_printf(const char *format, ...)
{
	va_list     arg;
	t_var       *var;
	int         n_printed;

	if (!(var = malloc(sizeof(t_var) + 1)))
		return (-1);
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			init_flags(var);
			format += find_flags(format, arg, var);
			check_type(*format, arg, var);
		}
		else
			var->printed_chars += ft_putchar(*format);
		format++;
	}
	n_printed = var->printed_chars;
	va_end(arg);
	free(var);
	return (n_printed);
}
