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
//PRINT INSTRUCTION
void	push(list *stack_push, list *stack_rem)
{
	if (stack_rem->first == NULL)
		return ;
    insert_first(stack_push, stack_rem->first->val);
    remove_first(stack_rem);
}


