/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:04:14 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/20 11:33:58 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (0);
	if (dest > src)
	{
		while (n--)
			((unsigned char *)dest)[n] = ((unsigned const char *)src)[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
