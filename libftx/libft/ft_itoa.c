/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:21:20 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/20 11:33:40 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_nbrlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*s;
	size_t	len;
	long	nbr;

	nbr = n;
	len = ft_nbrlen(n);
	s = (char *) malloc((len + 1) * sizeof(char));
	if (!s)
		return (0);
	s[len] = 0;
	if (nbr == 0)
		s[0] = '0';
	if (nbr < 0)
	{
		s[0] = '-';
		nbr = -nbr;
	}
	while (nbr != 0)
	{
			s[--len] = (nbr % 10) + '0';
			nbr = nbr / 10;
	}
	return (s);
}

/*#include <stdio.h>
int main(void)
{
    printf("%s \n",ft_itoa(0));
    printf("%s \n",ft_itoa(91));
    printf("%s \n",ft_itoa(-9));
    printf("%s \n",ft_itoa(10));
    printf("%s \n",ft_itoa(-10));
    printf("%s \n",ft_itoa(8124));
    printf("%s \n",ft_itoa(-9874));
    printf("%s \n",ft_itoa(-543000));
    printf("%s \n",ft_itoa(-2147483648));
    printf("%s \n",ft_itoa(2147483647));
    return (0);
}*/
