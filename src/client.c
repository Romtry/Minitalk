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

void kill_func(int pid, char c)
{
	unsigned int	bit_count;

	bit_count = 0;
	while (bit_count++ < 8)
	{
		if ((c & (0x01 << bit_count)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
	}
}

int main(int argc, char **argv)
{
    int pid;
    int i;

    i = 0;
    if (argc == 3)
    {
        pid = ft_atoi(argv[1]);
        while (argv[2][i++] != '\0')
            kill_func(pid, argv[2][i]);
        kill_func(pid, '\0');
    }
    else
    {
        write(1, "wrong input : ./client PID MESSAGE\n", 35);
        return(1);
    }
    return(0);
}