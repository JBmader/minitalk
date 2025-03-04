/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmader <jmader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:48:19 by jmader            #+#    #+#             */
/*   Updated: 2024/11/20 11:36:38 by jmader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

static int	handle_conversion(char format, va_list args)
{
	if (format == 'c')
		return (ft_print_char((char)va_arg(args, int)));
	else if (format == 's')
		return (ft_print_string(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_print_hexa(va_arg(args, void *)));
	else if (format == 'd' || format == 'i')
		return (ft_print_int(va_arg(args, int)));
	else if (format == 'u')
		return (ft_print_uint((unsigned int)va_arg(args, unsigned int)));
	else if (format == 'x')
		return (ft_print_lhexa(va_arg(args, unsigned int)));
	else if (format == 'X')
		return (ft_print_uhexa(va_arg(args, unsigned int)));
	else if (format == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed_chars;

	if (format == NULL)
		return (-1);
	printed_chars = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			printed_chars += handle_conversion(*format, args);
		}
		else
		{
			write(1, format, 1);
			printed_chars++;
		}
		format++;
	}
	va_end(args);
	return (printed_chars);
}
