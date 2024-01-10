/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:01:53 by gde-win           #+#    #+#             */
/*   Updated: 2024/01/10 03:36:13 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_input
{
	t_stack	*a;
	t_stack	*b;
	char	**av_copy;
	size_t	item_count;
	bool	av_copy_alloc;
}	t_input;

int		main(int ac, char **av);
void	ft_add_to_stack(int value, t_stack **node, t_input *data);
void	ft_call_push(t_stack **dst, t_stack **src, t_input *data);
void	ft_call_rotate(t_stack **A, t_stack **B, bool reverse);
void	ft_call_swap(t_stack **A, t_stack **B);
void	ft_check_args(int ac, char **av, t_input *data);
void	ft_do_push(t_stack **dst, t_stack **src);
void	ft_do_rotate(t_stack **stack, bool reverse);
void	ft_do_swap(t_stack **stack);
void	ft_error(t_input *data);
void	ft_free_input(t_input *data);
void	ft_free_stack(t_stack *data);
int		ft_get_max(t_stack *stack);
bool	ft_isinbounds(int n, char *nbr0);
bool	ft_isint(t_input *data);
bool	ft_issorted(t_stack *stack);
bool	ft_isunique(t_stack *stack);
void	ft_print_push(char c);
void	ft_print_rotate(char c);
void	ft_print_swap(char c);
void	ft_small_sort(t_input *data);
void	ft_sort(t_input *data);
void	ft_split_arg(char **av, t_input *data);

#endif
