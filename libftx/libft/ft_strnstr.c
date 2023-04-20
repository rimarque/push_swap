/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:30:27 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/20 11:35:13 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	find_little(const char *big, const char *little, size_t len, size_t i)
{
	size_t	j;

	j = 1;
	while (little[j] != 0)
	{
		if (big[i + 1] != little[j] || i + 1 >= len)
			return (0);
		j++;
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (i < len && big[i] != 0)
	{
		if (big[i] == little[0])
			if (!!find_little(big, little, len, i))
				return ((char *)big + i);
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>

int	main()
{
	printf("%s\n", ft_strnstr("aaabcabcd", "cd", 8));
	return(0);
}*/
