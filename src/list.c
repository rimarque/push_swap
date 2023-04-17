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
    /*node	*new;

    new = malloc(sizeof(node));
	if (!new)
		return ;
	new->val = nbr;*/
    new->next = NULL;
	new->prev = NULL;
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

/*void    remove_first(list *stack)
{
    node	*temp;
    temp = stack->first;
    ft_printf("--------------- 1 PASSO ---------------\n");
    ft_printf("stack->first->next->prev:val:%d, p:%p\n", stack->first->next->prev->val, stack->first->next->prev);
    ft_printf("stack->first->prev->next:val:%d, p:%p\n", stack->first->prev->next->val, stack->first->prev->next);
    ft_printf("stack->first:val:%d, p:%p\n", stack->first->val, stack->first);
    ft_printf("stack->first->prev:val:%d, p:%p\n", stack->first->prev->val, stack->first->prev);
    ft_printf("stack->first->next:val:%d, p:%p\n", stack->first->next->val, stack->first->next);/
	stack->first->next->prev = stack->first->prev;
    printf("1\n");
	stack->first->prev->next = stack->first->next;
    printf("2\n");
	stack->first = stack->first->next;
    printf("3\n");
    /ft_printf("--------------- 2 PASSO --------------\n");
    ft_printf("stack->first->next->prev:val:%d, p:%p\n", stack->first->next->prev->val, stack->first->next->prev);
    ft_printf("stack->first->prev->next:val:%d, p:%p\n", stack->first->prev->next->val, stack->first->prev->next);
    ft_printf("stack->first:val:%d, p:%p\n", stack->first->val, stack->first);
    ft_printf("stack->first->prev:val:%d, p:%p\n", stack->first->prev->val, stack->first->prev);
    ft_printf("stack->first->next:val:%d, p:%p\n", stack->first->next->val, stack->first->next);/
    free(temp);
    printf("4\n");
    /ft_printf("--------------- 3 PASSO --------------\n");
    ft_printf("stack->first->next->prev:val:%d, p:%p\n", stack->first->next->prev->val, stack->first->next->prev);
    ft_printf("stack->first->prev->next:val:%d, p:%p\n", stack->first->prev->next->val, stack->first->prev->next);
    ft_printf("stack->first:val:%d, p:%p\n", stack->first->val, stack->first);
    ft_printf("stack->first->prev:val:%d, p:%p\n", stack->first->prev->val, stack->first->prev);
    ft_printf("stack->first->next:val:%d, p:%p\n", stack->first->next->val, stack->first->next);/
    shift_index(stack);
    stack->size--;
}*/

void free_stack(list *stack)
{
    node    *element;
    node    *temp;
    int counter;

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
