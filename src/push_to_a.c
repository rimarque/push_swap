#include "../push_swap.h"

node *find_next_biggest(int nbr, list stack) //nbr da stack_b; stack_a
{
    node *result;
    node *element;

    result = stack.first;
    element = stack.first->next;
    while(element != stack.first)
    {
        while (result->val < nbr)
            result = result->next;
        if (result->val > element->val && element->val > nbr)
            result = element;
        element = element->next;
    }
    return(result);
}

node *find_smallest(list stack) //CHECK
{
    node *smallest;
    node *element;

    smallest = stack.first;
    element = stack.first->next;
    while(element != stack.first)
    {
        if (smallest->val > element->val)
            smallest = element;
        element = element->next;
    }
    return(smallest);
}

void rotate_a(int nbr, list *stack) //nbr de b, stack_a
{
    int flag;
    node *smallest;
    node *next_biggest;
    int counter;
    int nop_a;

    printf("NBR:%d\n", nbr); 
    if (is_big(nbr, *stack) || is_small(nbr, *stack)) 
    {
        //printf("is small or big\n");
        smallest = find_smallest(*stack);
        //printf("smallest:%d\n", smallest->val);    
        nop_a = count_r(smallest, stack->size, &flag);
    }
    else
    {
        next_biggest = find_next_biggest(nbr, *stack);
        //printf("next_biggest:%d\n", next_biggest->val);
        nop_a = count_r(next_biggest, stack->size, &flag);
    }
    counter = 0;
    while (counter++ < nop_a)
    {
        if (flag == 0)
            rotate(stack, 'a');
        if (flag == 1)
            rotate_rev(stack, 'a');
    }
}

void final_rotation(list *stack)
{
    node    *smallest;
    int counter;
    int flag;
    int nop_a;


    smallest = find_smallest(*stack);
    nop_a = count_r(smallest, stack->size, &flag);
    counter = 0;
    while (counter++ < nop_a)
    {
        if (flag == 0)
            rotate(stack, 'a');
        if (flag == 1)
            rotate_rev(stack, 'a');
    }
}