/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_costs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 00:09:41 by gde-win           #+#    #+#             */
/*   Updated: 2024/01/17 00:11:01 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clear_unnecessary_moves(t_move *cost, int ra_rrb, int rr, int rrr)
{
	if (cost->total == rr)
	{
		cost->rra = 0;
		cost->rrb = 0;
	}
	else if (cost->total == rrr)
	{
		cost->ra = 0;
		cost->rb = 0;
	}
	else if (cost->total == ra_rrb)
	{
		cost->rra = 0;
		cost->rb = 0;
	}
	else
	{
		cost->ra = 0;
		cost->rrb = 0;
	}
}

void	ft_compute_total(t_move *cost)
{
	int	ra_rrb;
	int	rra_rb;
	int	rr;
	int	rrr;

	rr = ft_max(cost->ra, cost->rb);
	if (cost->total > rr)
		cost->total = rr;
	rrr = ft_max(cost->rra, cost->rrb);
	if (cost->total > rrr)
		cost->total = rrr;
	ra_rrb = cost->ra + cost->rrb;
	if (cost->total > ra_rrb)
		cost->total = ra_rrb;
	rra_rb = cost->rra + cost->rb;
	if (cost->total > rra_rb)
		cost->total = rra_rb;
	ft_clear_unnecessary_moves(cost, ra_rrb, rr, rrr);
}

void	ft_find_target(t_stack *a, t_stack *b, size_t *j)
{
	if ((a->prev->index < b->index && b->index < a->index) \
			|| ((a->prev->index > a->index) \
				&& (a->prev->index < b->index || b->index < a->index)))
	{
		b->cost.ra = j;
		if (*j == 0)
			b->cost.rra = 0;
		else
			b->cost.rra = len_a - j;
	}
}

void	ft_compute_costs(t_stack *a, t_stack *b, size_t len_a, size_t len_b)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < len_b)
	{
		j = 0;
		while (j < len_a)
		{
			ft_find_target(a, b, &j);
			a = a->next;
			j++;
		}
		b->cost.rb = i;
		if (i == 0)
			b->cost.rrb = 0;
		else
			b->cost.rrb = len_b - i;
		ft_compute_total(&(b->cost));
		b = b->next;
		i++;
	}
}
