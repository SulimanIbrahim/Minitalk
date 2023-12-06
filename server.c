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
	static int max_bits;
	static int received_bits;
	int bit;
	int flag;
	printf("%d\n", signum);
	flag = 0;
	received_bits = 0;
		int check = received_bits;
		int j = 0;

		if(signum == SIGUSR1)
				bit = 0;
		else if(signum == SIGUSR2)
				bit = 1;
		else
			printf("receiving error");
		max_bits++;
		received_bits = received_bits << 1 | bit;
			// if(flag != -1)
			// 	printf("%c", (char)received_bits);
		if(max_bits == 8)
			printf("%d", received_bits);
}

int main()
{
	char *str = ft_itoa(getpid());
	signal(SIGUSR1, &handle_signal);
	signal(SIGUSR1, &handle_signal);
	int i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
	i++;
	}
	while(1)
		pause();
}
