/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:17:42 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/21 15:35:10 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*gft_calloc(size_t n)
{
	char	*dst;

	dst = (char *) malloc(n);
	if (!dst)
		return (0);
	while (n)
			dst[--n] = '\0';
	return (dst);
}

size_t	ft_strclen(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		i++;
	}
	if (str[i] == '\n')
		i++;
	return (i);
}

void	ft_strccpy(char *dst, char *src, char c)
{
	size_t	i;

	if (!*src)
		return ;
	i = 0;
	while (src[i] && src[i] != c)
	{
		dst[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
	{
		dst[i] = '\n';
		i++;
	}
	dst[i] = '\0';
}

char	*gft_strjoin(char *line, char **to_read)
{
	char	*dst;
	size_t	len_line;
	size_t	len_read;
	size_t	len_dst;

	len_line = ft_strclen(line, '\n');
	len_read = ft_strclen(*to_read, '\n');
	len_dst = len_line + len_read;
	dst = gft_calloc(len_dst + 1);
	ft_strccpy(dst, line, '\n');
	ft_strccpy((dst + len_line), *to_read, '\n');
	if (*line)
		free(line);
	if (dst[len_dst - 1] == '\n')
	{
		if (*to_read)
		{
			free(*to_read);
			*to_read = NULL;
		}
	}
	return (dst);
}
