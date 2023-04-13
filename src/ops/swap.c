/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:12:17 by rimarque          #+#    #+#             */
/*   Updated: 2023/03/30 22:12:19 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	swap(list *stack, char c)
{
	int	temp;

	if (stack->first == NULL || stack->first == stack->first->next)
		return ;
	temp = stack->first->val;
	stack->first->val = stack->first->next->val;
	stack->first->next->val = temp;
	if (c == 'a')
		ft_printf("sa\n");
	else if (c == 'b')
		ft_printf("sb\n");
}

void	swap_ss(list *stack_a, list *stack_b)
{
	swap(stack_a, 's');
	swap(stack_b, 's');
	ft_printf("ss\n");
}
