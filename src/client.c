/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbmader <jbmader@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:13:58 by jbmader           #+#    #+#             */
/*   Updated: 2025/02/21 15:27:51 by jbmader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile int	g_received = 0;

static void	handle_signal(int signal)
{
	if (signal == SIGUSR1)
		g_received = 1;
}

static void	send_bits(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_received = 0;
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_received)
			pause();
		bit++;
	}
}

static int	check_args(int argc, char **argv, int *server_pid)
{
	if (argc != 3)
	{
		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
		return (0);
	}
	*server_pid = ft_atoi(argv[1]);
	if (!*server_pid)
	{
		ft_printf("Invalid PID\n");
		return (0);
	}
	if (kill(*server_pid, 0) < 0)
	{
		ft_printf("Process with PID %d does not exist\n", *server_pid);
		return (0);
	}
	return (1);
}

static void	send_message(int server_pid, char *message)
{
	int	i;

	i = 0;
	signal(SIGUSR1, handle_signal);
	while (message[i] != '\0')
		send_bits(server_pid, message[i++]);
	if (i > 0)
		send_bits(server_pid, '\n');
}

int	main(int argc, char **argv)
{
	int	server_pid;

	if (!check_args(argc, argv, &server_pid))
		return (1);
	send_message(server_pid, argv[2]);
	return (0);
}
