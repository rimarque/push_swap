#include "../push_swap.h"

node *find_cheap(list stack_a, list stack_b)
{
    node *result;
    node *element;
    int n_op;
    int small_n_op = 0;
    int counter;

    element = stack_a.first;
    counter = 0;
    while(counter++ < stack_a.size)
    {
        n_op = count_op(element, stack_a.size, stack_b);
        //printf("n_op:%d\n", n_op);
        if (n_op == 0)                                       
        {
            //printf("entra aqui\n");
            result = element;
            break;
        }
        if (n_op < small_n_op || small_n_op == 0)
        {
            small_n_op = n_op;
            result = element;
        }
        element = element->next;
    }
    //printf("small_n_op:%d\n", small_n_op);
    return(result);
}

int is_big(int nbr, list stack) //CHECK 
{
    node *element;
    int counter;

    element = stack.first;
    /*if (nbr < element->val)
        return(0);
    element = element->next;*/
    counter = 0;
    while (counter++ < stack.size)
    {
        if (nbr < element->val)
            return(0);
        element = element->next;
    }
    return(1);
}

int is_small(int nbr, list stack) //CHECK
{
    node *element;
    int counter;

    element = stack.first;
    /*if (nbr > element->val)
        return(0);
    element = element->next;*/
    counter = 0;
    while (counter++ < stack.size)
    {
        if (nbr > element->val)
            return(0);
        element = element->next;
    }
    return(1);
}

node *find_biggest(list stack) //CHECK
{
    node *biggest;
    node *element;

    biggest = stack.first;
    element = stack.first->next;
    while(element != stack.first)
    {
        if (biggest->val < element->val)
            biggest = element;
        element = element->next;
    }
    return(biggest);
}

node *find_next_smallest(int nbr, list stack) //CHECK
{
    node *biggest;
    node *element;

    biggest = stack.first;
    element = stack.first->next;
    while(element != stack.first)
    {
        while (biggest->val > nbr)
            biggest = biggest->next;
        if (biggest->val < element->val && element->val < nbr)
            biggest = element;
        element = element->next;
    }
    return(biggest);
}

int count_r(node *element, int size, int *flag)     //CHECK
{
    int n_r;

    n_r = 0;
    if (element->index <= size/2) //rotate
    {
        *flag = 0;
        n_r += element->index;
    }
    else if (element->index > size/2) //rotate_rev
    {
        *flag = 1;
        n_r += size - element->index;
    }
    return(n_r);
}

int count_op_b(int nbr, list stack, int *flag) //CHECK
{
    node *biggest;
    node *next_smallest;
    int n_op_b;

    if (is_big(nbr, stack) || is_small(nbr, stack)) 
    {
        //printf("is small or big\n");
        biggest = find_biggest(stack);
        //printf("biggest:%d\n", biggest->val);
        n_op_b = count_r(biggest, stack.size, flag);
    }
    else
    {
        next_smallest = find_next_smallest(nbr, stack);
        //printf("next_smallest:%d\n", next_smallest->val);
        n_op_b = count_r(next_smallest, stack.size, flag);
    }
    return(n_op_b);
}

int count_op(node *element, int size, list stack)
{
    int result;
    int dif;
    int n_op_b;
    int n_op_a;
    int flag_a;
    int flag_b;

    flag_a = 0;
    flag_b = 0;

    //printf("START\nNBR:%d\n", element->val);
    n_op_a = count_r(element, size, &flag_a);
    element->nop_a = n_op_a;
    element->flag_a = flag_a;
    //printf("n_op_a:%d, flag:%d\n", n_op_a, flag_a);
    n_op_b = count_op_b(element->val, stack, &flag_b);
    element->nop_b = n_op_b;
    element->flag_b = flag_b;
    //printf("n_op_b:%d, flag:%d\n", n_op_b, flag_b);

    if (flag_a == flag_b) //SE FIZER ZERO OPERACOES A FLAG FICA = 0 - ATENCAO !!!!
    {
        //ft_printf("flag_a == a flag_b\n");
        if (n_op_a > n_op_b)
        {
            dif = n_op_a - n_op_b;
            result = n_op_b + dif;
        }
        else
        {
            dif = n_op_b - n_op_a;
            result = n_op_a + dif;
        }
    }
    else                                        //SE FOREM DIFERENTES VER OUTRAS OPCOES
        result = n_op_a + n_op_b;
    //ft_printf("RESULT:%d\n", result);
    return (result);
}