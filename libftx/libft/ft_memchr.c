/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:21:12 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/20 11:33:45 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cc_s;

	cc_s = (unsigned char *)s;
	i = 0;
	while (n > 0)
	{
		if (cc_s[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
		n--;
	}
	return (NULL);
}

/*#include <stdio.h>
int	main()
{
	const char str[] = {0, 1, 2 ,3 ,4 ,5};
	char *ret;

	ret = ft_memchr(str, 2 + 256, 3);
	printf("%s\n", ret);
	return (0);
}*/
