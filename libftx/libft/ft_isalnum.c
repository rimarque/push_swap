/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:04:33 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/20 11:33:17 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
