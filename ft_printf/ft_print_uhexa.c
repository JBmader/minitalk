/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uhexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmader <jmader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:42:40 by jmader            #+#    #+#             */
/*   Updated: 2024/11/19 10:20:33 by jmader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uhexa(unsigned int n)
{
	char	*hex;
	int		len;

	hex = "0123456789ABCDEF";
	len = 0;
	if (n >= 16)
		len += ft_print_uhexa(n / 16);
	ft_putchar_fd(hex[n % 16], 1);
	return (len + 1);
}
