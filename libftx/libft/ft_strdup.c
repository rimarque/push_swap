/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 21:22:27 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/20 11:34:38 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*new_s;

	len = ft_strlen(s) + 1;
	new_s = (char *) malloc(len * sizeof(char));
	if (!new_s)
		return (0);
	ft_strlcpy(new_s, s, len);
	return (new_s);
}

/*
#include <stdio.h>
int	main()
{
	char	str[] = "lorem ipsum dolor sit amet";
	char	*str_dup;

	str_dup = ft_strdup(str);
	printf("result is: %s\n", str_dup);
	return (0);
}*/
