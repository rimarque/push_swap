/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:44:59 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/20 11:57:05 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	shift_index(t_list *stack)
{
	t_node	*element;

	stack->first->index = 0;
	element = stack->first->next;
	while (element != stack->first)
	{
		element->index = element->prev->index + 1;
		element = element->next;
	}
}

void	put_first_node(t_list *stack, t_node *new)
{
	stack->first = new;
	new->next = stack->first;
	new->prev = stack->first;
}

t_node	*remove_first(t_list *stack)
{
	t_node	*temp;

	temp = stack->first;
	if (stack->size == 1)
		stack->first = NULL;
	else
	{
		stack->first->next->prev = stack->first->prev;
		stack->first->prev->next = stack->first->next;
		stack->first = stack->first->next;
		shift_index(stack);
	}
	stack->size--;
	return (temp);
}

void	insert_first(t_list *stack, t_node *new)
{
	if (stack->first == NULL)
		put_first_node(stack, new);
	else
	{
		new->next = stack->first;
		new->prev = stack->first->prev;
		stack->first->prev->next = new;
		stack->first->prev = new;
		stack->first = new;
	}
	shift_index(stack);
	stack->size++;
}

void	free_stack(t_list *stack)
{
	t_node	*element;
	t_node	*temp;
	int		counter;

	if (stack->first == NULL)
		return ;
	element = stack->first;
	counter = 0;
	while (counter++ < stack->size)
	{
		temp = element;
		element = element->next;
		free(temp);
	}
	stack->first = NULL;
	stack->size = 0;
}
