/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:26:48 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/19 20:26:49 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	count_op_b(int nbr, t_list stack, int *flag)
{
	t_node	*biggest;
	t_node	*next_smallest;
	int		nop_b;

	if (is_big(nbr, stack) || is_small(nbr, stack))
	{
		biggest = find_biggest(stack);
		nop_b = count_r(biggest, stack.size, flag);
	}
	else
	{
		next_smallest = find_next_smallest(nbr, stack);
		nop_b = count_r(next_smallest, stack.size, flag);
	}
	return (nop_b);
}

int	count_op(t_node *element, int size, t_list stack)
{
	int	result;
	int	dif;

	element->nop_a = count_r(element, size, &element->flag_a);
	element->nop_b = count_op_b(element->val, stack, &element->flag_b);
	if (element->flag_a == element->flag_b)
	{
		if (element->nop_a > element->nop_b)
		{
			dif = element->nop_a - element->nop_b;
			result = element->nop_b + dif;
		}	
		else
		{	
		dif = element->nop_b - element->nop_a;
		result = element->nop_a + dif;
		}
	}
	else
		result = element->nop_a + element->nop_b;
	return (result);
}

t_node	*find_cheap(t_list stack_a, t_list stack_b)
{
	t_node	*result;
	t_node	*element;
	int		nop;
	int		small_nop;
	int		counter;

	element = stack_a.first;
	small_nop = 0;
	counter = 0;
	while (counter++ < stack_a.size)
	{
		nop = count_op(element, stack_a.size, stack_b);
		if (nop == 0)
		{
			result = element;
			break ;
		}
		if (nop < small_nop || small_nop == 0)
		{
			small_nop = nop;
			result = element;
		}
		element = element->next;
	}
	return (result);
}
