/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmader <jmader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:25:52 by jmader            #+#    #+#             */
/*   Updated: 2024/11/18 20:01:15 by jmader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
int		ft_print_char(char c);
int		ft_print_string(char *str);
int		ft_print_int(int n);
int		ft_print_uint(unsigned int n);
int		ft_print_hexa(void *ptr);
int		ft_print_lhexa(unsigned int n);
int		ft_print_uhexa(unsigned int n);
int		ft_printf(const char *format, ...);

#endif