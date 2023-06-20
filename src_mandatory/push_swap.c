/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:49:19 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/26 12:42:39 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	stack_a;
	t_list	stack_b;

	if (argc == 1)
		return (0);
	create_stack(&stack_a);
	create_stack(&stack_b);
	insert_stack_a(&stack_a, argc, argv);
	ft_isdouble(&stack_a);
	if (argc == 2 || ft_issorted(&stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	algorithm(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
