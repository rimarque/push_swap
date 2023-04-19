/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:16:26 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/19 21:16:52 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

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
			rotate_rr(stack_a, stack_b);
		if (flag == 1)
			rotate_rev_rr(stack_a, stack_b);
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
	int		flag;
	t_node	*smallest;
	t_node	*next_biggest;
	int		nop;

	if (is_big(nbr, *stack) || is_small(nbr, *stack))
	{
		smallest = find_smallest(*stack);
		nop = count_r(smallest, stack->size, &flag);
	}
	else
	{
		next_biggest = find_next_biggest(nbr, *stack);
		nop = count_r(next_biggest, stack->size, &flag);
	}
	rotate_stack(stack, 'a', nop, flag);
}

void	move_to_a(t_list *stack_a, t_list *stack_b, int size)
{
	int		counter;
	t_node	*element;

	counter = 0;
	while (counter++ < size)
	{
		element = stack_b->first;
		rotate_a(element->val, stack_a);
		push(stack_a, 'a', stack_b);
	}
}
