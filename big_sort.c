/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:41:07 by gde-win           #+#    #+#             */
/*   Updated: 2024/01/17 00:12:09 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_best_move_2(t_input *data, t_move cost)
{
	while (cost.rb > 0)
	{
		ft_call_rotate(NULL, &(data->b), false);
		cost.rb--;
	}
	while (cost.rra > 0)
	{
		ft_call_rotate(&(data->a), NULL, true);
		cost.rra--;
	}
	while (cost.rrb > 0)
	{
		ft_call_rotate(NULL, &(data->b), true);
		cost.rrb--;
	}
	ft_call_push(&(data->a), &(data->b), data);
}

void	ft_do_best_move(t_input *data, t_move cost)
{
	while (cost.ra > 0 && cost.rb > 0)
	{
		ft_call_rotate(&(data->a), &(data->b), false);
		cost.ra--;
		cost.rb--;
	}
	while (cost.rra > 0 && cost.rrb > 0)
	{
		ft_call_rotate(&(data->a), &(data->b), true);
		cost.rra--;
		cost.rrb--;
	}
	while (cost.ra > 0)
	{
		ft_call_rotate(&(data->a), NULL, false);
		cost.ra--;
	}
	ft_do_best_move_2(data, cost);
}

void	ft_call_best_move(t_input *data, t_stack *b, size_t len)
{
	int		best;
	size_t	i;

	best = b->cost.total;
	i = 0;
	while (i < len)
	{
		if (best > b->cost.total)
			best = b->cost.total;
		b = b->next;
		i++;
	}
	while (best != b->cost.total)
		b = b->next;
	ft_do_best_move(data, b->cost);
}

void	ft_big_sort(t_input *data)
{
	size_t	len_a;
	size_t	len_b;

	while (ft_isascending(data->a) == false && ft_stacklen(data->a, &len_a) > 3)
		ft_call_push(&(data->b), &(data->a), data);
	if (len_a == 3)
		ft_small_sort(data);
	while (data->b != NULL)
	{
		ft_stacklen(data->a, &len_a);
		ft_stacklen(data->b, &len_b);
		ft_reset_costs(data->b, len_a, len_b);
		ft_compute_costs(data->a, data->b, len_a, len_b);
		ft_call_best_move(data, data->b, len_b);
	}
	ft_only_rotate(data, len_a);
}
