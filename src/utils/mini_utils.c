/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:44:29 by rothiery          #+#    #+#             */
/*   Updated: 2024/09/30 15:54:47 by rothiery         ###   ########.fr       */
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

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			write(1, &s[i], 1);
			i++;
		}
	}
}

static size_t	get_digits(int n)
{
	size_t	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char    *ft_itoa(int n)
{
	char		*str_num;
	size_t		digits;
	long int	num;

	num = n;
	digits = get_digits(n);
	if (n < 0)
	{
		num *= -1;
		digits++;
	}
	if (!(str_num = (char *)malloc(sizeof(char) * (digits + 1))))
		return (NULL);
	*(str_num + digits) = 0;
	while (digits--)
	{
		*(str_num + digits) = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		*(str_num + 0) = '-';
	return (str_num);
}