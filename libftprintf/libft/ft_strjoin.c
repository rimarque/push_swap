/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:52:32 by rimarque          #+#    #+#             */
/*   Updated: 2022/11/29 18:52:47 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_s;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_s = (char *) malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!new_s)
		return (0);
	ft_strlcpy(new_s, s1, (s1_len + 1));
	ft_strlcpy((new_s + s1_len), s2, (s2_len + 1));
	return (new_s);
}
