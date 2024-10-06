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

void	ft_handler(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		bit = 0;
		i = 0;
	}
}

int main(int argc, char **argv)
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
	while (1)
	{
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
		pause ();
	}
	return (0);
}