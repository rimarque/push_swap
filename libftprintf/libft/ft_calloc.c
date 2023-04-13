/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 21:07:47 by rimarque          #+#    #+#             */
/*   Updated: 2022/11/28 21:07:52 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dst;

	dst = (void *) malloc(nmemb * size);
	if (!dst)
		return (0);
	ft_bzero(dst, nmemb * size);
	return (dst);
}
