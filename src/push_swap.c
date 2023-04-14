/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:49:19 by rimarque          #+#    #+#             */
/*   Updated: 2023/03/13 13:49:24 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    print_list_val(list stack, char c)
{
    ft_printf("VAL");
    ft_printf("\nsize of list: %d\n", stack.size);
    node    *element = stack.first;
    //printf("stack first: %p\n", stack.first);
    //printf("element: %p\n", element);
    //printf("prev element: %p\n", element->prev);
    if (c == 'a')
        printf("STACK A");
    else
        printf("STACK B");
    if(element)
    {
        printf("\n%d\n", element->val);
        element = element->next;
        while(element != stack.first)
        {
            //printf("element: %p\n", element);
            //printf("prev element: %p\n", element->prev);
            printf("%d\n", element->val);
            element = element->next;
        }
    }
}

void    print_list_index(list stack, char c)
{
    ft_printf("INDEX");
    ft_printf("\nsize of list: %d\n", stack.size);
    node    *element = stack.first;
    //printf("stack first: %p\n", stack.first);
    //printf("element: %p\n", element);
    //printf("prev element: %p\n", element->prev);
    if (c == 'a')
        printf("STACK A");
    else
        printf("STACK B");
    if(element)
    {
        printf("\n%d\n", element->index);
        element = element->next;
        while(element != stack.first)
        {
            //printf("element: %p\n", element);
            //printf("prev element: %p\n", element->prev);
            printf("%d\n", element->index);
            element = element->next;
        }
    }
}

void    print_val_index(list stack_a, list stack_b)
{
    node    *element_a = stack_a.first;
    node    *element_b = stack_b.first;

    int counter = 0;
    ft_printf("size of stack_a: %d\nsize of stack_b: %d\n", stack_a.size, stack_b.size);
    ft_printf("STACK A        STACK B\n");
    if(element_a || element_b)
    {
        while(counter < stack_a.size || counter < stack_b.size)
        {
            //printf("counter:%d\n", counter);
            if (counter >= stack_b.size || stack_b.first == NULL)
                printf("%d (%d)\n", element_a->val, element_a->index);
            else if (counter >= stack_a.size || stack_a.first == NULL)
                printf("               %d (%d)\n", element_b->val, element_b->index);
            else
                printf("%d (%d)         %d (%d)\n", element_a->val, element_a->index, element_b->val, element_b->index);
            if (stack_a.first != NULL)
                element_a = element_a->next;
            if (stack_b.first != NULL)
                element_b = element_b->next;
            counter++;
        }
    }
}

int main(int argc, char **argv)
{
    list    stack_a;
    list    stack_b;
    //node *element;
    //int flag = 0;
    //int test;
    int  i;
    //int counter = 0;

    if(argc == 1)
        return(0);
    create_list(&stack_a);
    create_list(&stack_b);
    //insert_last(&stack_b, -1);
    //insert_last(&stack_b, 67);
    i = 1;
    while(i < argc)
    {
        ft_isnbr(argv[i]);
        ft_isint(ft_atoi(argv[i]));
        insert_last(&stack_a, ft_atoi(argv[i]));
        i++;
    }
    ft_isdouble(&stack_a);
    //algorithm(&stack_a, &stack_b);
    //rotate(&stack_a, 'a');
    //rotate_rev_rr(&stack_a, &stack_b);
    //push(&stack_b, &stack_a);
    //swap(&stack_a, 'a');
    sort3(&stack_a);
    /*element = stack_a.first;
    while (counter++ < stack_a.size)
    {
        test = count_r(element, stack_a.size, &flag);
        ft_printf("n_op:%d\nflag:%d\n", test, flag);
        element = element->next;
    }*/
    //test = count_op_b(20, stack_a, &flag);
    //ft_printf("n_op:%d\nflag:%d\n", test, flag);
    //print_list_val(stack_a, 'a');
    //print_list_val(stack_b, 'b');
    //print_list_index(stack_a, 'a');
    //print_list_index(stack_b, 'b');
    print_val_index(stack_a, stack_b);
    //free_stack(&stack_a);
    //free_stack(&stack_b);
}
