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

static int	ft_atoi(char *str)
{
	int			sign;
	long long	res;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0')
	{
		if(*str >= '0' && *str <= '9')
			res = res * 10 + *str - '0';
		else
		{
			ft_printf("WRONG PID found non ineteger\n");
			exit(1);
		}
		if (res > 2147483647 || res < -2147483648)
		{
			return (0);
		}
		str++;
	}
	return (res * sign); 
}

int convert_to_bits(unsigned char c, int pid)
{
	int	bit;
	int	ascii;
	int	i;
	int flag = 0;

	i = 7;
	ascii = (int) c;
	while (i >= 0)
	{
		bit = ascii >> i & 1;
		if(bit == 0)
			flag = kill(pid, SIGUSR1);
		else if (bit == 1)
			flag = kill(pid, SIGUSR2);
		if (flag == -1)
			{
				ft_printf("WRONG PID\n");
				exit(1);
			}
		usleep(1500);

		i--;
	}
	return (bit);
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (av[1][0] <= '0' || av[1][0] > '9' || pid < 0)
		{
			ft_printf("INVALID PID\n");
			exit(1);
		}
		else if (!av[2][0])
			ft_printf(
				"Sending an empty message, type somthing ya Rasta !\n");
		while (av[2][i])
		{
			convert_to_bits(av[2][i], pid);
			i++;
		}
	} else 
		{
			ft_printf("IVALID NUMBER OF ARGUMENTS !\n");
			exit(1);
		}
}