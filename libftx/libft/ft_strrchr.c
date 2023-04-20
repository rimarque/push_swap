/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:38:56 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/20 11:35:20 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;

	s_len = ft_strlen(s) + 1;
	while (s_len--)
		if (s[s_len] == (unsigned char)c)
			return ((char *)s + s_len);
	return (NULL);
}

/*int	main()
{
	char c = '\0';

	printf("%s\n", ft_strrchr("rita", c));
	return (0);
}*/
