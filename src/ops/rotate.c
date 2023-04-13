/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:06:20 by rimarque          #+#    #+#             */
/*   Updated: 2023/03/30 22:06:25 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rotate(list *stack, char c)
{
	if (stack->first == NULL || stack->first == stack->first->next)
		return ;
	stack->first = stack->first->next;
	shift_index(stack);
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
}

void	rotate_rr(list *stack_a, list *stack_b)
{
	rotate(stack_a, 'r');
	rotate(stack_b, 'r');
	ft_printf("rr\n");
}

void	rotate_rev(list *stack, char c)
{
	if (stack->first == NULL || stack->first->next == stack->first)
		return ;
	stack->first = stack->first->prev;
	shift_index(stack);
	if (c == 'a')
		ft_printf("rra\n");
	else if (c == 'b')
		ft_printf("rrb\n");
}

void	rotate_rev_rr(list *stack_a, list *stack_b)
{
	rotate_rev(stack_a, 'r');
	rotate_rev(stack_b, 'r');
	ft_printf("rrr\n");
}
