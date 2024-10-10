/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:19:56 by rothiery          #+#    #+#             */
/*   Updated: 2024/09/30 13:44:09 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	atoirep(const char *nptr, int i)
{
	int	rep;

	rep = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		rep = (rep * 10) + (nptr[i] - 48);
		i++;
	}
	return (rep);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	s;

	s = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-')
	{
		s = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	if (nptr[i] < '0' || nptr[i] > '9')
		return (0);
	else
		return (atoirep(nptr, i) * s);
}

int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	kill_func(int pid, char c)
{
	unsigned int	bit_count;

	bit_count = 0;
	while (bit_count < 8)
	{
		if ((c & (0x01 << bit_count)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(300);
		bit_count++;
	}
}

int	main(int argc, char **argv)
{
	int				pid;
	unsigned int	i;

	i = 0;
	if (ft_strlen(argv[2]) > 1024)
	{
		ft_putstr("\e[1;97m[!] - Reached the limit (1024 characters)!\n\e[0m");
		exit(1);
	}
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][++i - 1] != '\0')
			kill_func(pid, argv[2][i - 1]);
		kill_func(pid, '\0');
	}
	else
	{
		write(1, "wrong input : ./client PID MESSAGE\n", 35);
		return (1);
	}
	return (0);
}
