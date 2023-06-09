/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:06:20 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/20 19:09:15 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate(t_list *stack, char c)
{
	if (stack->size <= 1)
		return ;
	stack->first = stack->first->next;
	shift_index(stack);
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
}

void	rotate_rr(t_list *stack_a, t_list *stack_b, int flag)
{
	rotate(stack_a, 'r');
	rotate(stack_b, 'r');
	if (!flag)
		ft_printf("rr\n");
}

void	rotate_rev(t_list *stack, char c)
{
	if (stack->size <= 1)
		return ;
	stack->first = stack->first->prev;
	shift_index(stack);
	if (c == 'a')
		ft_printf("rra\n");
	else if (c == 'b')
		ft_printf("rrb\n");
}

void	rotate_rev_rr(t_list *stack_a, t_list *stack_b, int flag)
{
	rotate_rev(stack_a, 'r');
	rotate_rev(stack_b, 'r');
	if (!flag)
		ft_printf("rrr\n");
}
