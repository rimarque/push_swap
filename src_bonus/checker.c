/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:49:19 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/23 18:03:12 by rimarque         ###   ########.fr       */
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
	ft_isdouble(&stack_a);
	if (argc == 2 || ft_issorted(&stack_a))
		does_nothing(&stack_a, &stack_b);
	nop = sort(&stack_a, &stack_b);
	if (ft_issorted(&stack_a) && stack_b.size == 0)
		ft_printf("OK (%d operations executed)\n", nop);
	else
		ft_printf("KO\n");
	free_stack(&stack_a);
	free_stack(&stack_b);
}
