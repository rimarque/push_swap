/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:45:24 by rimarque          #+#    #+#             */
/*   Updated: 2022/11/22 16:45:27 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*#include <stdio.h>
int main()
{
    const char *str;

    str = "rita";
    printf("%s is: %u\n", str, ft_strlen(str));
    str = "outlander; ";
    printf("%s is: %u\n", str, ft_strlen(str));
    str = "";
    printf("%s is: %u\n", str, ft_strlen(str));
    return (0);
}*/
