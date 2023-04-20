/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:42:36 by rimarque          #+#    #+#             */
/*   Updated: 2023/01/12 17:44:03 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_put_c(char c);
int	ft_put_s(char *s);
int	ft_put_id(int n);
int	ft_put_u(unsigned int n);
int	ft_put_x(unsigned long long n, char format);
int	ft_put_p(unsigned long long p);
int	ft_printf(const char *s_format, ...);

#endif
