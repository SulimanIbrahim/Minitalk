/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 05:52:04 by suibrahi          #+#    #+#             */
/*   Updated: 2023/08/15 03:17:20 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnum(int num)
{
	char	*arr;
	int		len;
	int		i;

	i = 0;
	arr = ft_itoa(num);
	len = ft_putstring(arr);
	free (arr);
	return (len);
}
