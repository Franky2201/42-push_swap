/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:01:53 by gde-win           #+#    #+#             */
/*   Updated: 2024/01/07 01:05:21 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int		value;
	t_stack	*next;
	t_stack	*prev;
}	t_stack;

typedef struct s_parsed_list
{
	t_stack	*stack_A;
	t_stack	*stack_B;
	size_t	item_count;
	char	**av_copy;
	bool	stack_alloc;
	bool	av_copy_alloc;
}	t_parsed_list;

int		main(int ac, char **av);
void	ft_check_args(int *ac, char ***av, t_parsed_list *list);
void	ft_error(t_parsed_list list);
void	ft_free(t_parsed_list list);
bool    ft_isinbounds(int n, char *nbr0);
bool	ft_isint(t_parsed_list *list);
bool	ft_isunique(t_parsed_list *list);
void	ft_malloc_stack(t_parsed_list *list);
void	ft_split_arg(char ***av, t_parsed_list *list);

#endif
