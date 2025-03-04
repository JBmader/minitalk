/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmader <jmader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:31:22 by jmader            #+#    #+#             */
/*   Updated: 2024/11/19 10:42:32 by jmader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_recursive(unsigned long long n)
{
	char	*hex;
	int		len;

	hex = "0123456789abcdef";
	len = 0;
	if (n >= 16)
		len += ft_print_recursive(n / 16);
	ft_putchar_fd(hex[n % 16], 1);
	return (len + 1);
}

int	ft_print_hexa(void *ptr)
{
	int	len;

	len = 2;
	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	len += ft_print_recursive((unsigned long long)ptr);
	return (len);
}
