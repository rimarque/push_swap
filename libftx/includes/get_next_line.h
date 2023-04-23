/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:49:10 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/23 18:00:53 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3

# endif

char	*get_next_line(int fd);
char	*gft_strjoin(char *temp, char **to_read);
void	ft_strccpy(char *dst, char *src, char c);
size_t	ft_strclen(const char *str, char c);
int		count_nl(char *str);
char	*gft_calloc(size_t n);

#endif
