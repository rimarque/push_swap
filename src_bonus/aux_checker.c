/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:10:01 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/21 20:55:12 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error_bonus(char *str, t_list *stack_a, t_list *stack_b)
{
	free(str);
	free_stack(stack_a);
	free_stack(stack_b);
	ft_printf("Error\n");
	exit(0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	sort(t_list *stack_a, t_list *stack_b)
{
	char	*str;
	int		nop;

	nop = 0;
	while (1)
	{
		str = get_next_line(STDIN_FILENO);
		if (str == NULL)
			break ;
		do_ops(str, stack_a, stack_b);
		free(str);
		nop++;
	}
	return (nop);
}

void	do_ops(char *str, t_list *stack_a, t_list *stack_b)
{
	if (!ft_strcmp(str, "pa\n"))
		push(stack_a, 'c', stack_b);
	else if (!ft_strcmp(str, "pb\n"))
		push (stack_b, 'c', stack_a);
	else if (!ft_strcmp(str, "ra\n"))
		rotate(stack_a, 'c');
	else if (!ft_strcmp(str, "rb\n"))
		rotate(stack_b, 'c');
	else if (!ft_strcmp(str, "rr\n"))
		rotate_rr(stack_a, stack_b, 1);
	else if (!ft_strcmp(str, "rra\n"))
		rotate_rev(stack_a, 'c');
	else if (!ft_strcmp(str, "rrb\n"))
		rotate_rev(stack_b, 'c');
	else if (!ft_strcmp(str, "rrr\n"))
		rotate_rev_rr(stack_a, stack_b, 1);
	else if (!ft_strcmp(str, "sa\n"))
		swap(stack_a, 'c');
	else if (!ft_strcmp(str, "sb\n"))
		swap(stack_b, 'c');
	else if (!ft_strcmp(str, "ss\n"))
		swap_ss(stack_a, stack_b, 1);
	else
		ft_error_bonus(str, stack_a, stack_b);
}

int	check_ops(char *str)
{
	if (!ft_strcmp(str, "pa\n") || !ft_strcmp(str, "pb\n")
		|| !ft_strcmp(str, "ra\n") || !ft_strcmp(str, "rb\n")
		|| !ft_strcmp(str, "rr\n") || !ft_strcmp(str, "rra\n")
		|| !ft_strcmp(str, "rrb\n") || !ft_strcmp(str, "rrr\n")
		|| !ft_strcmp(str, "sa\n") || !ft_strcmp(str, "sb\n")
		|| !ft_strcmp(str, "ss\n"))
		return (1);
	return (0);
}
