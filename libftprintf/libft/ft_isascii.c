/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:18:15 by rimarque          #+#    #+#             */
/*   Updated: 2022/11/22 16:20:20 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/* #include <stdio.h>
int main()
{
    unsigned char c;
    c = 'A';
    printf("%c is: %d\n", c, ft_isascii(c));
    c = 'f';
    printf("%c is: %d\n", c, ft_isascii(c));
    c = '!';
    printf("%c is: %d\n", c, ft_isascii(c));
    c = 133;
    printf("%c is: %d\n", c, ft_isascii(c));
    c = '[';
    printf("%c is: %d\n", c, ft_isascii(c));
    c = 42;
    printf("%c is: %d\n", c, ft_isascii(c));
    c = '9';
    printf("%c is: %d\n", c, ft_isascii(c));
    return (0);
} */
