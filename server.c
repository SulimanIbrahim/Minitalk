/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:35:30 by suibrahi          #+#    #+#             */
/*   Updated: 2023/12/04 23:05:20 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"
void handle_signal(int signum)
{
	static unsigned char received_bits;
	int bit;

	bit = (signum == SIGUSR2) ? 1 : 0;
			if (signum == -1)
			{
				ft_printf("receiving error\n");
				exit(1);
			}
		max_bits++;

		received_bits = (received_bits << 1) | bit;
		if(max_bits == 8)
		{
			write(1,&received_bits,1);
			received_bits = '\0';
			max_bits = 0;
		}
}

int main()
{
	signal(SIGUSR1, &handle_signal);
	signal(SIGUSR2, &handle_signal);
	ft_printf("%d\n", getpid());
	while(1)
		pause();
	return (0);
}
