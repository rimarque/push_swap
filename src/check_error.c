/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:06:44 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/19 19:29:18 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_isnbr(const char *str, t_list *stack)
{
	if (*str == '-' || *str == '+')
			str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			free_stack(stack);
			ft_printf("Error\n");
			exit(0);
		}
		str++;
	}
}

void	ft_isint(long long nbr, t_list *stack)
{
	if (nbr > 2147483647 || nbr < -2147483648)
	{
		free_stack(stack);
		ft_printf("Error\n");
		exit(0);
	}
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
			{
				free_stack(stack);
				ft_printf("Error\n");
				exit(0);
			}
			element_b = element_b->next;
		}
		element_a = element_a->next;
	}
}
