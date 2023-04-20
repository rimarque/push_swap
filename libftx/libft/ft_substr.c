/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:03:30 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/20 11:35:34 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;
	size_t	len_s;

	len_s = ft_strlen(s);
	if (!s)
		return (0);
	sub_s = (char *) malloc((len + 1) * sizeof (char));
	if (!sub_s)
		return (0);
	i = 0;
	if (start <= len_s)
	{
		while (i < len_s && i < len)
		sub_s[i++] = s[start++];
	}
	sub_s[i] = 0;
	return (sub_s);
}

/*#include <stdio.h>
int		main()
{
	char	*str_dup;

	str_dup = ft_substr("hola", 0, 18446744073709551615);
	printf("result is: %s\n", str_dup);
	return (0);
}*/
