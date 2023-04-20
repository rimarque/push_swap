/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:09:40 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/20 11:34:31 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*l27: se i == len significa que chegou ao fim da string sem encontrar o int c
ou c = '\0);*/

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	i = 0;
	while (s[i] != (unsigned char)c && s[i] != '\0')
		i++;
	if (i == len && (unsigned char)c != 0)
		return (NULL);
	return ((char *)s + i);
}

/*#include <stdio.h>
int	main()
{
	printf("%s\n", ft_strchr("tripouille", 't' + 256));
	return (0);
}*/
