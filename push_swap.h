/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:01:53 by gde-win           #+#    #+#             */
/*   Updated: 2024/01/17 00:17:11 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_move
{
	int	total;
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
}	t_move;

typedef struct s_stack
{
	int				value;
	size_t			index;
	struct s_move	cost;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_input
{
	t_stack	*a;
	t_stack	*b;
	char	**av_copy;
	int		*stack_copy;
	size_t	item_count;
	bool	av_copy_alloc;
	bool	stack_copy_alloc;
}	t_input;

int		main(int ac, char **av);
void	ft_add_to_copy(int value, int *copy, size_t index);
void	ft_add_to_stack(int value, t_stack **node, t_input *data);
void	ft_assign_index_to_nodes(t_input *data);
void	ft_big_sort(t_input *data);
void	ft_call_best_move(t_input *data, t_stack *b, size_t len);
void	ft_call_push(t_stack **dst, t_stack **src, t_input *data);
void	ft_call_rotate(t_stack **A, t_stack **B, bool reverse);
void	ft_call_swap(t_stack **A, t_stack **B);
void	ft_check_args(int ac, char **av, t_input *data);
void	ft_clear_unnecessary_moves(t_move *cost, int ra_rrb, int rr, int rrr);
void	ft_compute_costs(t_stack *a, t_stack *b, size_t len_a, size_t len_b);
void	ft_compute_total(t_move *cost);
void	ft_do_best_move_1(t_input *data, t_move cost);
void	ft_do_best_move_2(t_input *data, t_move cost);
void	ft_do_push(t_stack **dst, t_stack **src);
void	ft_do_rotate(t_stack **stack, bool reverse);
void	ft_do_swap(t_stack **stack);
void	ft_error(t_input *data);
void	ft_find_target(t_stack *a, t_stack *b, size_t *j);
void	ft_free_input(t_input *data);
void	ft_free_stack(t_stack *data);
bool	ft_isascending(t_stack *stack);
bool	ft_isdigit_and_inbounds(int n, char *nbr0);
bool	ft_isint(t_input *data);
bool	ft_issorted(t_stack *stack);
bool	ft_isunique(t_stack *stack);
int		ft_max(int a, int b);
void	ft_only_rotate(t_input *data, size_t len);
void	ft_print_push(char c);
void	ft_print_rotate(char c);
void	ft_print_swap(char c);
void	ft_remove_node(t_stack **stack);
void	ft_reset_costs(t_stack *stack, size_t len_a, size_t len_b);
void	ft_small_sort(t_input *data);
void	ft_sort(t_input *data);
void	ft_sort_stack_copy(t_input *data);
void	ft_split_arg(char **av, t_input *data);
size_t	ft_stacklen(t_stack *stack, size_t *len);

#endif
