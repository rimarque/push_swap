#include "../push_swap.h"

void    create_list(list *stack)
{
    stack->first = NULL;
    stack->size = 0;
}

void    insert_last(list *stack, int nbr)
{
    static int index = 0;

    node *new;
    
    new = malloc(sizeof(node));
    if (!new)
        return ;
    new->val = nbr;
    if (stack->first == NULL)
    {
        index = 0;
        stack->first = new;
        new->next = stack->first;
        new->prev = stack->first;
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

void    insert_first(list *stack, node *new)
{
	if (stack->first == NULL)
	{
        stack->first = new;
		new->next = stack->first;
		new->prev = stack->first;
	}
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

node    *remove_first(list *stack)
{
    node	*temp;

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

void free_stack(list *stack)
{
    node    *element;
    node    *temp;
    int counter;

    if (stack->first ==  NULL)
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

void shift_index(list *stack)
{
    node    *element;
    
    stack->first->index = 0;
    element = stack->first->next;
    while (element != stack->first)
    {
        element->index = element->prev->index + 1;
        element = element->next;
    }
}
