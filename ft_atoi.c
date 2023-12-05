/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 02:26:13 by suibrahi          #+#    #+#             */
/*   Updated: 2023/12/03 04:46:04 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

int	ft_atoi(char *str)
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
	while (*str >= '0' && *str <= '9' )
	{
		res = res * 10 + *str - '0';
		if (res > 2147483647 || res < -2147483648)
		{
			return (0);
		}
		str++;
	}
	return (res * sign); 
}
