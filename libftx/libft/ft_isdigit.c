/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:22:33 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/20 11:33:32 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/* #include <stdio.h>
int main()
{
    unsigned char c;
    c = 'A';
    printf("%c is: %d\n", c, ft_isdigit(c));
    c = 'f';
    printf("%c is: %d\n", c, ft_isdigit(c));
    c = '!';
    printf("%c is: %d\n", c, ft_isdigit(c));
    c = 133;
    printf("%c is: %d\n", c, ft_isdigit(c));
    c = '[';
    printf("%c is: %d\n", c, ft_isdigit(c));
    c = 42;
    printf("%c is: %d\n", c, ft_isdigit(c));
    c = '9';
    printf("%c is: %d\n", c, ft_isdigit(c));
    return (0);
} */
