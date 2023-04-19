/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:05:06 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/19 20:08:59 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	count_r(t_node *element, int size, int *flag)
{
	int	nr;

	nr = 0;
	if (element->index <= size / 2)
	{
		*flag = 0;
		nr += element->index;
	}
	else if (element->index > size / 2)
	{
		*flag = 1;
		nr += size - element->index;
	}
	return (nr);
}

int	is_big(int nbr, t_list stack)
{
	t_node	*element;
	int		counter;

	element = stack.first;
	counter = 0;
	while (counter++ < stack.size)
	{
		if (nbr < element->val)
			return (0);
		element = element->next;
	}
	return (1);
}

int	is_small(int nbr, t_list stack)
{
	t_node	*element;
	int		counter;

	element = stack.first;
	counter = 0;
	while (counter++ < stack.size)
	{
		if (nbr > element->val)
			return (0);
		element = element->next;
	}
	return (1);
}
