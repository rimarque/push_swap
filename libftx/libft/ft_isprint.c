/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:24:56 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/20 11:33:36 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

/*#include <stdio.h>
int main()
{
    char c;
    c = 'A';
    printf("%c is: %d\n", c, ft_isprint(c));
    c = 'f';
    printf("%c is: %d\n", c, ft_isprint(c));
    c = '!';
    printf("%c is: %d\n", c, ft_isprint(c));
    c = -1;
    printf("%c is: %d\n", c, ft_isprint(c));
    c = '[';
    printf("%c is: %d\n", c, ft_isprint(c));
    c = 42;
    printf("%c is: %d\n", c, ft_isprint(c));
    c = '9';
    printf("%c is: %d\n", c, ft_isprint(c));
    c = 0;
    printf("%c is: %d\n", c, ft_isprint(c));
    return (0);
}*/
