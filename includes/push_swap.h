/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:49:34 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/21 17:29:18 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libftx/includes/libft.h"
# include "../libftx/includes/ft_printf.h"
# include "../libftx/includes/get_next_line.h"

typedef struct t_node
{
	struct t_node		*prev;
	int					val;
	int					index;
	int					nop_a;
	int					nop_b;
	int					flag_a;
	int					flag_b;
	struct t_node		*next;
}t_node;

typedef struct t_list
{
	struct t_node	*first;
	int				size;
}t_list;

//create_stack
void			create_stack(t_list *stack);
void			insert_last(t_list *stack, int nbr);

//stack
void			shift_index(struct t_list *stack);
void			put_first_node(struct t_list *stack, struct t_node *new);
struct t_node	*remove_first(struct t_list *stack);
void			insert_first(struct t_list *stack, struct t_node *new);
void			free_stack(struct t_list *stack);

//check_error
void			ft_error(t_list *stack);
void			ft_isnbr(const char *str, struct t_list *stack);
void			ft_isint(long long nbr, struct t_list *stack);
void			ft_isdouble(struct t_list *stack);

//OPS
//push
void			push(struct t_list *dst, char c, struct t_list *src);
//rotate
void			rotate(struct t_list *stack, char c);
void			rotate_rr(struct t_list *stack_a, struct t_list *stack_b, int flag);
void			rotate_rev(struct t_list *stack, char c);
void			rotate_rev_rr(struct t_list *stack_a, struct t_list *stack_b, int flag);
//swap
void			swap(struct t_list *stack, char c);
void			swap_ss(struct t_list *stack_a, struct t_list *stack_b, int flag);

//ALGORITHM
//algorithm
void			algorithm(struct t_list *stack_a, struct t_list *stack_b);
//sort3
void			sort3(struct t_list *stack);
//costs
struct t_node	*find_cheap(struct t_list stack_a, struct t_list stack_b);
int				count_op(struct t_node *element, int size, struct t_list stack);
//aux
int				count_r(struct t_node *element, int size, int *flag);
int				is_big(int nbr, struct t_list stack);
int				is_small(int nbr, struct t_list stack);
//aux_find
struct t_node	*find_biggest(struct t_list stack);
struct t_node	*find_next_smallest(int nbr, struct t_list stack);
struct t_node	*find_smallest(struct t_list stack);
struct t_node	*find_next_biggest(int nbr, struct t_list stack);
//aux_move
void			rotate_stack(struct t_list *stack, char c, int nop, int flag);
void			rotate_both(struct t_list *stack_a,
					struct t_list *stack_b, int nop, int flag);
void			move_to_b(struct t_node *element,
					struct t_list *stack_a, struct t_list *stack_b);
void			rotate_a(int nbr, struct t_list *stack);
void			move_to_a(struct t_list *stack_a, struct t_list *stack_b);

//BONUS
//sort
int				ft_strcmp(const char *s1, const char *s2);
void 			do_ops(char *str, struct t_list *stack_a, struct t_list *stack_b);
int				sort(struct t_list *stack_a, struct t_list *stack_b);
int				check_ops(char *str);
void			ft_error_bonus(t_list *stack_a, t_list *stack_b);
#endif
