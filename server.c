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
	int i = 0;
	while (i < 8)
	{
		if(signum == 30)
			
	else if (signum == 31) 
		printf("\nRecieving bit : %d \n", 1);
		i++;
	}
}

int main()
{
	char *str = ft_itoa(getpid());
	signal(SIGUSR2, handle_signal);
	int i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
	i++;
	}
	sleep(500);
}
