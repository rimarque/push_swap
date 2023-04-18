/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:06:44 by rimarque          #+#    #+#             */
/*   Updated: 2023/03/30 22:06:49 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_isnbr(const char *str, list *stack)
{
	if (*str == '-' || *str == '+')
			str++;
	while(*str)
	{
		if (*str < '0' || *str > '9')
		{
			free_stack(stack);
			ft_printf("Error\n");
        	exit(0);
        }
        str++;
	}
}

void	ft_isint(long long nbr, list *stack)
{
    if (nbr > 2147483647 || nbr < -2147483648 )
    {
		free_stack(stack);
		ft_printf("Error\n");
        exit(0);
    }
}

void	ft_isdouble(list	*stack)
{
		node	*element_a;
		node	*element_b;

		element_a = stack->first;
		//ate ao penultimo elemento
		while(element_a != stack->first->prev)
		{
			//ate ao ultimo elemento
			element_b = element_a->next;
			while(element_b != stack->first)
			{
				//comparar o 1o elemento com os restantes
				if(element_a->val == element_b->val)
				{
					free_stack(stack);
					ft_printf("Error\n");
        			exit(0);
				}
				element_b = element_b->next;
			}
			element_a = element_a->next;
		}
}

void	ft_issorted(list	*stack)
{
		node	*element_a;
		node	*element_b;

		element_a = stack->first;
		element_b = element_a->next;
		while(element_b != stack->first)
		{
			if(element_a->val > element_b->val)
				return ;
			element_a = element_a->next;
			element_b = element_a->next;
		}
		free_stack(stack);
        exit(0);
}
