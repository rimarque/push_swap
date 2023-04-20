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
