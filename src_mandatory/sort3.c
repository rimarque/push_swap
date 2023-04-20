/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:02:43 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/20 15:26:29 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort3(t_list *stack)
{
	if (stack->first->val > stack->first->next->val
		&& stack->first->val < stack->first->prev->val)
		swap(stack, 'a');
	else if (stack->first->val > stack->first->next->val
		&& stack->first->next->val > stack->first->prev->val)
	{
		swap(stack, 'a');
		rotate_rev(stack, 'a');
	}
	else if (stack->first->val > stack->first->next->val
		&& stack->first->val > stack->first->prev->val)
		rotate(stack, 'a');
	else if (stack->first->val < stack->first->prev->val
		&& stack->first->next->val > stack->first->prev->val)
	{
		swap(stack, 'a');
		rotate(stack, 'a');
	}
	else if (stack->first->val < stack->first->next->val
		&& stack->first->val > stack->first->prev->val)
		rotate_rev(stack, 'a');
}
