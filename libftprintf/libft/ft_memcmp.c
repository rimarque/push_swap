/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:12:30 by rimarque          #+#    #+#             */
/*   Updated: 2022/11/25 12:39:08 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*cc_s1;
	const char	*cc_s2;

	cc_s1 = s1;
	cc_s2 = s2;
	i = 0;
	while (i < n)
	{
		if (cc_s1[i] != cc_s2[i])
			return ((unsigned char)cc_s1[i] - (unsigned char)cc_s2[i]);
		i++;
	}
	return (0);
}
