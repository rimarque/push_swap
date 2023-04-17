/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:07:01 by rimarque          #+#    #+#             */
/*   Updated: 2023/03/30 22:07:13 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
void	push(list *stack_push, char c, list *stack_rem)
{
	if (stack_rem->first == NULL)
		return ;
  insert_first(stack_push, remove_first(stack_rem));
  if (c == 'a')
    ft_printf("pa\n");
  else if (c == 'b')
    ft_printf("pb\n");
}
