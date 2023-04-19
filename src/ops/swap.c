/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:12:17 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/19 18:02:29 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	swap(t_list *stack, char c)
{
	int	temp;

	if (stack->size <= 1)
		return ;
	temp = stack->first->val;
	stack->first->val = stack->first->next->val;
	stack->first->next->val = temp;
	if (c == 'a')
		ft_printf("sa\n");
	else if (c == 'b')
		ft_printf("sb\n");
}

void	swap_ss(t_list *stack_a, t_list *stack_b)
{
	swap(stack_a, 's');
	swap(stack_b, 's');
	ft_printf("ss\n");
}
