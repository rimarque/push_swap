/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:16:26 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/20 19:19:40 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_stack(t_list *stack, char c, int nop, int flag)
{
	int		counter;

	counter = 0;
	while (counter++ < nop)
	{
		if (flag == 0)
			rotate(stack, c);
		if (flag == 1)
			rotate_rev(stack, c);
	}
}

void	rotate_both(t_list *stack_a, t_list *stack_b, int nop, int flag)
{
	int		counter;

	counter = 0;
	while (counter++ < nop)
	{
		if (flag == 0)
			rotate_rr(stack_a, stack_b, 0);
		if (flag == 1)
			rotate_rev_rr(stack_a, stack_b, 0);
	}
}

void	move_to_b(t_node *element, t_list *stack_a, t_list *stack_b)
{
	int		dif;

	if (element->flag_a == element->flag_b)
	{
		if (element->nop_a > element->nop_b)
		{
			dif = element->nop_a - element->nop_b;
			rotate_stack(stack_a, 'a', dif, element->flag_a);
			rotate_both(stack_a, stack_b, element->nop_b, element->flag_a);
		}
		else
		{
			dif = element->nop_b - element->nop_a;
			rotate_stack(stack_b, 'b', dif, element->flag_b);
			rotate_both(stack_a, stack_b, element->nop_a, element->flag_a);
		}
	}
	else
	{
		rotate_stack(stack_a, 'a', element->nop_a, element->flag_a);
		rotate_stack(stack_b, 'b', element->nop_b, element->flag_b);
	}
	push(stack_b, 'b', stack_a);
}

void	rotate_a(int nbr, t_list *stack)
{
	t_node	*element;

	if (is_big(nbr, *stack) || is_small(nbr, *stack))
		element = find_smallest(*stack);
	else
		element = find_next_biggest(nbr, *stack);
	element->nop_a = count_r(element, stack->size, &element->flag_a);
	rotate_stack(stack, 'a', element->nop_a, element->flag_a);
}

void	move_to_a(t_list *stack_a, t_list *stack_b)
{
	t_node	*element;

	while (stack_b->size)
	{
		element = stack_b->first;
		rotate_a(element->val, stack_a);
		push(stack_a, 'a', stack_b);
	}
}
