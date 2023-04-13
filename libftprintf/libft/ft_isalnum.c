/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:04:33 by rimarque          #+#    #+#             */
/*   Updated: 2022/11/21 19:12:28 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

/* #include <stdio.h>
int main()
{
    unsigned char c;
    c = 'A';
    printf("%c is: %d\n", c, ft_isalnum(c));
    c = 'f';
    printf("%c is: %d\n", c, ft_isalnum(c));
    c = '!';
    printf("%c is: %d\n", c, ft_isalnum(c));
    c = 133;
    printf("%c is: %d\n", c, ft_isalnum(c));
    c = '[';
    printf("%c is: %d\n", c, ft_isalnum(c));
    c = 42;
    printf("%c is: %d\n", c, ft_isalnum(c));
    c = '9';
    printf("%c is: %d\n", c, ft_isalnum(c));
    return (0);
} */
