/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:35:30 by suibrahi          #+#    #+#             */
/*   Updated: 2023/12/07 21:08:07 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

static void	handle_signal(int signum)
{
	static unsigned char	received_bits;
	static int				max_bits;
	int						bit;

	bit = 0;
	if (signum == SIGUSR2)
		bit = 1;
	else if (signum == -1)
	{
		ft_printf("Undefined bit\n");
		exit(1);
	}
	max_bits++;
	received_bits = (received_bits << 1) | bit;
	if (max_bits == 8)
	{
		write(1, &received_bits, 1);
		received_bits = '\0';
		max_bits = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, &handle_signal);
	signal(SIGUSR2, &handle_signal);
	ft_printf("%d\n", getpid());
	while (1)
		pause();
	return (0);
}
