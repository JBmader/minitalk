/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmader <jmader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:55:37 by jmader            #+#    #+#             */
/*   Updated: 2024/11/19 10:17:55 by jmader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	ft_uintlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_putunbr(unsigned int n)
{
	char	c;

	if (n > 9)
	{
		ft_putunbr(n / 10);
	}
	c = n % 10 + '0';
	write(1, &c, 1);
}

int	ft_print_uint(unsigned int n)
{
	ft_putunbr(n);
	return (ft_uintlen(n));
}
