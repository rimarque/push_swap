/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:49:19 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/23 10:36:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*check_first_call(t_list *stack_a, t_list *stack_b)
{
	char	*str;

	str = get_next_line(STDIN_FILENO);
	if (str == NULL)
	{
		ft_printf("OK\n");
		free_stack(stack_a);
		free_stack(stack_b);
		exit(0);
	}
	if (!check_ops(str))
		ft_error_bonus(str, stack_a, stack_b);
	return (str);
}

void	does_nothing(t_list *stack_a, t_list *stack_b)
{
	char	*str;

	str = check_first_call(stack_a, stack_b);
	while (1)
	{
		ft_free(&str);
		str = get_next_line(STDIN_FILENO);
		if (str == NULL)
			break ;
		if (!check_ops(str))
			ft_error_bonus(str, stack_a, stack_b);
		ft_free(&str);
	}
	ft_printf("KO\n");
	free_stack(stack_a);
	free_stack(stack_b);
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

int	main(int argc, char **argv)
{
	t_list	stack_a;
	t_list	stack_b;
	int		nop;

	if (argc == 1)
		return (0);
	create_stack(&stack_a);
	create_stack(&stack_b);
	insert_stack_a(&stack_a, argc, argv);
	if (argc == 2)
	{
		check_errors(argv[1], &stack_a);
		does_nothing(&stack_a, &stack_b);
	}
	ft_isdouble(&stack_a);
	if (ft_issorted_bonus(&stack_a))
		does_nothing(&stack_a, &stack_b);
	nop = sort(&stack_a, &stack_b);
	if (ft_issorted_bonus(&stack_a) && stack_b.size == 0)
		ft_printf("OK (%d operations executed)\n", nop);
	else
		ft_printf("KO\n");
	free_stack(&stack_a);
	free_stack(&stack_b);
}
