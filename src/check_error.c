/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:06:44 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/21 21:09:43 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(t_list *stack)
{
	free_stack(stack);
	ft_printf("Error\n");
	exit(0);
}

void	ft_isnbr(const char *str, t_list *stack)
{
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		ft_error(stack);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			ft_error(stack);
		str++;
	}
}

void	ft_isint(long long nbr, t_list *stack)
{
	if (nbr > 2147483647 || nbr < -2147483648)
		ft_error(stack);
}

void	ft_isdouble(t_list	*stack)
{
	t_node	*element_a;
	t_node	*element_b;

	element_a = stack->first;
	while (element_a != stack->first->prev)
	{
		element_b = element_a->next;
		while (element_b != stack->first)
		{
			if (element_a->val == element_b->val)
				ft_error(stack);
			element_b = element_b->next;
		}
		element_a = element_a->next;
	}
}

void	check_errors(char *str, t_list *stack)
{
	ft_isnbr(str, stack);
	ft_isint(ft_atoi(str), stack);
}
