/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 17:44:26 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/23 17:44:26 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	create_stack(t_list *stack)
{
	stack->first = NULL;
	stack->size = 0;
}

void	insert_last(t_list *stack, int nbr)
{
	static int	index = 0;
	t_node		*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->val = nbr;
	if (stack->first == NULL)
	{
		index = 0;
		put_first_node(stack, new);
	}
	else
	{
		index = index + 1;
		stack->first->prev->next = new;
		new->prev = stack->first->prev;
		new->next = stack->first;
		stack->first->prev = new;
	}
	new->index = index;
	stack->size++;
}

void	insert_stack_a(t_list *stack, int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		ft_isnbr(argv[i], stack);
		ft_isint(ft_atoi(argv[i]), stack);
		insert_last(stack, ft_atoi(argv[i]));
		i++;
	}
}

int	ft_issorted(t_list *stack)
{
	t_node	*element_a;
	t_node	*element_b;

	element_a = stack->first;
	element_b = element_a->next;
	while (element_b != stack->first)
	{
		if (element_a->val > element_b->val)
			return (0);
		element_a = element_a->next;
		element_b = element_a->next;
	}
	return (1);
}
