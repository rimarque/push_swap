/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_iduxXp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:51:04 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/20 11:32:42 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_nbrlen(unsigned long long n, int base)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		len++;
		n = n / base;
	}
	return (len);
}

int	ft_put_u(unsigned int n)
{
	if (n >= 10)
		ft_put_u(n / 10);
	ft_put_c(n % 10 + 48);
	return (ft_nbrlen(n, 10));
}

int	ft_put_id(int n)
{
	int	len;

	if (n == -2147483648)
		return (ft_put_s("-2147483648"));
	len = 0;
	if (n < 0)
	{
		ft_put_c('-');
		n = -n;
		len++;
	}
	len += ft_put_u(n);
	return (len);
}

int	ft_put_x(unsigned long long n, char format)
{
	if (n >= 16)
		ft_put_x(n / 16, format);
	if (n % 16 < 10)
		ft_put_c(n % 16 + 48);
	else
	{
		if (format == 'X')
			ft_put_c(n % 16 + 55);
		else
			ft_put_c(n % 16 + 87);
	}
	return (ft_nbrlen(n, 16));
}

int	ft_put_p(unsigned long long p)
{
	int	len;

	if (p == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write (1, "0x", 2);
	len = ft_put_x(p, 'x');
	return (2 + len);
}
