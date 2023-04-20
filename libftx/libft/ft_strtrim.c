/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:29:10 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/20 11:35:29 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*new_s;

	if (!s1)
		return (0);
	i = 0;
	while (!!ft_strchr(set, s1[i]) && s1[i] != 0)
			i++;
	len = ft_strlen(s1);
	if (i != len)
	{
		while (!!ft_strchr(set, s1[len - 1]))
			len--;
	}
	new_s = (char *) malloc((len + 1 - i) * sizeof (char));
	if (!new_s)
		return (0);
	ft_strlcpy(new_s, (s1 + i), (len + 1 - i));
	return (new_s);
}

/*int main()
{
	char *s1 = "  \t \t \n   \n\n\n\t";
	char *ret = ft_strtrim(s1, " \n\t");
	printf("result 1 is: %s\n", ret);

	char *s2 = "";
	char *ret1 = ft_strtrim(s2, " \n\t");
	printf("result 2 is: %s\n", ret1);
}



int main()
{
	char *s1 = "  \t \t \n   \n\n\n\t";
	char *ret = ft_strtrim(s1, " \n\t");
	printf("result is: %s\n", ret);
}*/
