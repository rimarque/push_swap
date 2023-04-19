/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:49:34 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/19 18:23:49 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libftprintf/libft/libft.h"
# include "./libftprintf/printf/ft_printf.h"

typedef struct node
{
	struct node		*prev;
	int				val;
	int				index;
	int				nop_a;
	int				nop_b;
	int				flag_a;
	int				flag_b;
	struct node		*next;
}t_node;

typedef struct t_list
{
	struct node	*first;
	int			size;
}t_list;

//list
void		shift_index(struct t_list *stack);
void		put_first_node(struct t_list *stack, struct node *new);
struct node	*remove_first(struct t_list *stack);
void		insert_first(struct t_list *stack, struct node *new);
void		free_stack(struct t_list *stack);

//check_error
void		ft_isnbr(const char *str, struct t_list *stack);
void		ft_isint(long long nbr, struct t_list *stack);
void		ft_isdouble(struct t_list *stack);

//OPS
//push
void		push(struct t_list *stack_push, char c, struct t_list *stack_rem);
//rotate
void		rotate(struct t_list *stack, char c);
void		rotate_rr(struct t_list *stack_a, struct t_list *stack_b);
void		rotate_rev(struct t_list *stack, char c);
void		rotate_rev_rr(struct t_list *stack_a, struct t_list *stack_b);
//swap
void		swap(struct t_list *stack, char c);
void		swap_ss(struct t_list *stack_a, struct t_list *stack_b);

//ALGORITHM
//algorithm
void		algorithm(struct t_list *stack_a, struct t_list *stack_b);
//sort3
void		sort3(struct t_list *stack);
//costs
struct node	*find_cheap(struct t_list stack_a, struct t_list stack_b);
int			count_op(struct node *element, int size, struct t_list stack);
//aux
int			count_r(struct node *element, int size, int *flag);
int			is_big(int nbr, struct t_list stack);
int			is_small(int nbr, struct t_list stack);
//aux_find
struct node	*find_biggest(struct t_list stack);
struct node	*find_next_smallest(int nbr, struct t_list stack);
struct node	*find_smallest(struct t_list stack);
struct node	*find_next_biggest(int nbr, struct t_list stack);
//aux_move
void		rotate_stack(struct t_list *stack, char c, int nop, int flag);
void		rotate_both(struct t_list *stack_a,
				struct t_list *stack_b, int nop, int flag);
void		move_to_b(struct node *element,
				struct t_list *stack_a, struct t_list *stack_b);
void		rotate_a(int nbr, struct t_list *stack);
void		move_to_a(struct t_list *stack_a, struct t_list *stack_b, int size);

#endif
