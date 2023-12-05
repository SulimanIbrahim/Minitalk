/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:47:07 by suibrahi          #+#    #+#             */
/*   Updated: 2023/12/04 23:13:26 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

int convert_to_bits(char c, int pid)
{
	int	bit;
	int	ascii;
	int	i;
	int max;

	i = 0;
	ascii = (int) c;
	while (i < 8)
	{
		bit = ascii / (1 << i) % 2;
		if(bit == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(50);
	}
			printf("\n");

	return (bit);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;
	int	pid;

	i = 1;
	j = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[2]);
		while (av[i][j])
		{
			convert_to_bits(av[i][j], pid);
			j++;
		}
	}
}