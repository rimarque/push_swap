/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:58:27 by rimarque          #+#    #+#             */
/*   Updated: 2022/11/25 16:56:07 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	long long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	nbr *= sign;
	//printf("nbr:%d", nbr);
	return (nbr);
}
/*#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char str[] = "\t\n\r\v\fd469 \n";
	printf("ft_atoi int is: %d\n", ft_atoi(str));
	char real_str[] = "\t\n\r\v\fd469 \n";
	printf("atoi int is: %d\n", atoi(real_str));
	return (0);	
}*/
