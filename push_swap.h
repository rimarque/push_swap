/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:49:34 by rimarque          #+#    #+#             */
/*   Updated: 2023/03/13 13:53:30 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libftprintf/libft/libft.h"
# include "./libftprintf/printf/ft_printf.h"

typedef struct node
{
	struct node *prev;
	int val;
	int index;
	int nop_a;
	int nop_b;
	int flag_a;
	int flag_b;
	struct node *next;
}node;

typedef struct
{
	node *first;
	int size;
}list;

//list
void    create_list(list *stack);
void    insert_last(list *stack, int nbr);
void    insert_first(list *stack, int nbr);
void    remove_first(list *stack);
void	shift_index(list *stack);
void free_stack(list *stack);

//check_error
void	ft_isnbr(const char *str);
void 	ft_isint(long long nbr);
void	ft_isdouble(list	*stack);

//ops
void    swap(list *stack, char c);
void    swap_ss(list *stack_a, list *stack_b);
void    push(list *stack_a, list *stack_b);
void    rotate(list *stack, char c);
void    rotate_rr(list *stack_a, list *stack_b);
void    rotate_rev(list *stack, char c);
void    rotate_rev_rr(list *stack_a, list *stack_b);

//sort
void 	sort3(list *stack);

//find_cheap
node *find_cheap(list stack_a, list stack_b);
int is_big(int nbr, list stack);
int is_small(int nbr, list stack);
node *find_biggest(list stack);
node *find_next_smallest(int nbr, list stack);
int count_r(node *element, int size, int *flag);
int count_op_b(int nbr, list stack, int *flag);
int count_op(node *element, int size, list stack);

//algorithm
void algorithm(list *stack_a, list *stack_b);
#endif
