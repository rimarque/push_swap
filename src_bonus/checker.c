/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:49:19 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/20 21:34:26 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    print_val_index(t_list stack_a, t_list stack_b)
{
    t_node    *element_a = stack_a.first;
    t_node    *element_b = stack_b.first;

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

void	does_nothing(t_list *stack)
{
	if (get_next_line(STDIN_FILENO) == NULL)
			ft_printf("OK1\n");
	else
		ft_printf("KO\n");
	if (stack->first != NULL)
		free_stack(stack);
	exit (0);
}

int	ft_issorted_bonus(t_list *stack)
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

int	main(int argc, char **argv)
{
	t_list	stack_a;
	t_list	stack_b;
	int		i;
	int		nop;

	create_stack(&stack_a);
	create_stack(&stack_b);
	if (argc <= 2)
		does_nothing(&stack_a);
	i = 1;
	while (i < argc)
	{
		ft_isnbr(argv[i], &stack_a);
		ft_isint(ft_atoi(argv[i]), &stack_a);
		insert_last(&stack_a, ft_atoi(argv[i]));
		i++;
	}
	ft_isdouble(&stack_a);
	if (ft_issorted_bonus(&stack_a))
		does_nothing(&stack_a);
	nop = sort(&stack_a, &stack_b);
	if (ft_issorted_bonus(&stack_a) && stack_b.size == 0)
		ft_printf("OK\n%d operations were executed\n", nop);
	else
		ft_printf("KO\n");
	//print_val_index(stack_a, stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
