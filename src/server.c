/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:54:12 by rothiery          #+#    #+#             */
/*   Updated: 2024/09/30 15:56:17 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	convert(int signal)
{
	static unsigned int	bit;
	static char			save[1025];
	static unsigned int	i;
	static unsigned int	index;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{ 
		if (index == 1025)
		{
			write(1, "error of signal\n", 16);
			exit (1);
		}
		save[index++] = i;
		if (i == '\0')
		{
			index = 0;
			usleep(300);
			ft_putstr(save);
			write(1, "\n", 1);
		}
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*tmp;

	(void)argv;
	if (argc != 1)
	{
		write(1, "wrong input ./server\n", 21);
		return (1);
	}
	pid = getpid();
	tmp = ft_itoa(pid);
	ft_putstr(tmp);
	free(tmp);
	write(1, " waiting  for message\n", 22);
	signal(SIGUSR1, convert);
	signal(SIGUSR2, convert);
	while (1)
		pause ();
	return (0);
}
