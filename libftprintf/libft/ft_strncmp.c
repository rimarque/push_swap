/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:43:05 by rimarque          #+#    #+#             */
/*   Updated: 2022/11/24 18:53:09 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*int main() 
{
  char str1[] = "abcd";
  char str2[] = "abCd";
  char str3[] = "abcd";
  char str4[] = "abcdut";
  char str5[] = "asgsh";
  char str6[]="hh";
  int result;
  int n;
  n = (100);

  //comparing strings str1 and str2
  result = ft_strncmp(str1, str2, n);
  printf("strcmp(str1, str2) = %d\n", result);

  // comparing strings str1 and str3
  result = ft_strncmp(str1, str3, n);
  printf("strcmp(str1, str3) = %d\n", result);

   // comparing strings str1 and str4
  result = ft_strncmp(str1, str4, n);
  printf("strcmp(str1, str4) = %d\n", result);

  // comparing strings str1 and str5
  result = ft_strncmp(str1, str5, n);
  printf("strcmp(str1, str5) = %d\n", result);

   // comparing strings str1 and str6
  result = ft_strncmp(str1, str6, n);
  printf("strcmp(str1, str6) = %d\n", result);

   // comparing strings str1 and str2
  result = strncmp(str1, str2, n);
  printf("strcmp(str1, str2) = %d\n", result);

  // comparing strings str1 and str3
  result = strncmp(str1, str3, n);
  printf("strcmp(str1, str3) = %d\n", result);

   // comparing strings str1 and str4
  result = strncmp(str1, str4, n);
  printf("strcmp(str1, str4) = %d\n", result);

  // comparing strings str1 and str5
  result = strncmp(str1, str5, n);
  printf("strcmp(str1, str5) = %d\n", result);

   // comparing strings str1 and str6
  result = strncmp(str1, str6, n);
  printf("strcmp(str1, str6) = %d\n", result);

  return 0;
 }*/
