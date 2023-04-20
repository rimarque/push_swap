/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:27:22 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/20 11:34:04 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*new_str;

	new_str = str;
	i = 0;
	while (i < n)
	{
		new_str[i] = c;
		i++;
	}
	return (new_str);
}

/* #include <stdio.h>
#include <string.h>
int	main(void)
{
	unsigned char 	str[] = "migas com cheesy bites";
	unsigned char	*ptr;
    unsigned char   *test;

	ptr = ft_memset(str, '-', 7);
    test = memset(str, '-', 7);
	printf("Result(-7): %s\n", ptr);
    printf("Result(-7): %s\n", test);

    ptr = ft_memset(str, 'u', 12);
    test = memset(str, 'u', 12);
	printf("Result(u12): %s\n", ptr);
    printf("Result(u12): %s\n", test);

    ptr = ft_memset(str, '\0', 3);
	printf("Result(NUL3): %s\n", ptr);
    test = memset(str, '\0', 3);
    printf("Result_real(NUL3): %s\n", test);
    return (0);
} */
