/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:01:43 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/20 15:25:58 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*find_biggest(t_list stack)
{
	t_node	*result;
	t_node	*element;

	result = stack.first;
	element = stack.first->next;
	while (element != stack.first)
	{
		if (result->val < element->val)
			result = element;
		element = element->next;
	}
	return (result);
}

t_node	*find_next_smallest(int nbr, t_list stack)
{
	t_node	*result;
	t_node	*element;

	result = stack.first;
	element = stack.first->next;
	while (element != stack.first)
	{
		while (result->val > nbr)
			result = result->next;
		if (result->val < element->val && element->val < nbr)
			result = element;
		element = element->next;
	}
	return (result);
}

t_node	*find_smallest(t_list stack)
{
	t_node	*smallest;
	t_node	*element;

	smallest = stack.first;
	element = stack.first->next;
	while (element != stack.first)
	{
		if (smallest->val > element->val)
			smallest = element;
		element = element->next;
	}
	return (smallest);
}

t_node	*find_next_biggest(int nbr, t_list stack)
{
	t_node	*result;
	t_node	*element;

	result = stack.first;
	element = stack.first->next;
	while (element != stack.first)
	{
		while (result->val < nbr)
			result = result->next;
		if (result->val > element->val && element->val > nbr)
			result = element;
		element = element->next;
	}
	return (result);
}
