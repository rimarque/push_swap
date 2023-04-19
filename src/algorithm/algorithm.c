/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:00:16 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/19 20:00:17 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	final_rotation(t_list *stack)
{
	t_node	*smallest;

	smallest = find_smallest(*stack);
	smallest->nop_a = count_r(smallest, stack->size, &smallest->flag_a);
	rotate_stack(stack, 'a', smallest->nop_a, smallest->flag_a);
}

void	algorithm(t_list *stack_a, t_list *stack_b)
{
	t_node	*element;

	if (stack_a->size > 3)
	{
		push(stack_b, 'b', stack_a);
		if (stack_a->size > 4)
			push(stack_b, 'b', stack_a);
	}
	while (stack_a->size > 3)
	{
		element = find_cheap(*stack_a, *stack_b);
		move_to_b(element, stack_a, stack_b);
	}
	sort3(stack_a);
	if (stack_b->size == 0)
		return ;
	move_to_a(stack_a, stack_b, stack_b->size);
	final_rotation(stack_a);
}
