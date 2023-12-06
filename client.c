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
	int flag = 0;

	i = 0;
	ascii = (int) c;
	while (i < 8)
	{
		bit = ascii >> i & 1;
		if(bit == 0)
			flag = kill(pid, SID)
		else if (bit == 1)
			printf("%d\n", bit);
		if (flag == -1)
			{
				perror("Error sending signal");
				exit(EXIT_FAILURE);
			}

		i++;
		usleep(50);
	}
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