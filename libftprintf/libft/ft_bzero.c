/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:49:33 by rimarque          #+#    #+#             */
/*   Updated: 2022/11/21 18:59:58 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	ft_memset(str, '\0', n);
}

/* #include <string.h>
#include <stdio.h>
int main()
{
    char    str[] = "the coconut nut is not a nut";
    ft_bzero(str, 5);
    printf("str is: %s\n", str);

    char    test[] = "the coconut nut is not a nut";
    bzero(test, 5);
    printf("test is: %s\n", test);
    return (0);
} */
