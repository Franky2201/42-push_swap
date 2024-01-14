/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:41:07 by gde-win           #+#    #+#             */
/*   Updated: 2024/01/14 04:43:43 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_home(t_input *data, t_qualities *info, t_move *cost)
{
	int		rr;
	int		i;
	bool	reverse;
	size_t	len_a;
	size_t	len_b;

	len_b = info->len;
	len_a = data->item_count - len_b;
	rr = ft_return_min_abs(cost->ra, cost->rb);
	i = -1;
	reverse = false;
	if (rr < 0)
	{
		i = 1;
		reverse = true;
	}
	if (ft_issamesign(cost->ra, cost->rb) == true)
	{
		cost->ra -= rr;
		cost->rb -= rr;
		while (rr != 0)
		{
			ft_call_rotate(&(data->a), &(data->b), reverse);
			rr += i;
		}
		while (cost->ra != 0)
		{
			ft_call_rotate(&(data->a), NULL, reverse);
			cost->ra += i;
		}
		while (cost->rb != 0)
		{
			ft_call_rotate(NULL, &(data->b), reverse);
			cost->rb += i;
		}
	}
	else if (rr == cost->ra)
	{
		if (ft_abs(cost->ra - cost->rb) > (int)len_b / 2)
		{
			if (cost->rb < 0)
				cost->rb += len_b;
			else
				cost->rb -= len_b;
			ft_push_home(data, info, cost);
			return ;
		}
	}
	else if (rr == cost->rb)
	{
		if (ft_abs(cost->rb - cost->ra) > (int)len_a / 2)
		{
			if (cost->ra < 0)
				cost->ra += len_a;
			else
				cost->ra -= len_a;
			ft_push_home(data, info, cost);
			return ;
		}
	}
	if (cost->ra < 0)
	{
		i = 1;
		reverse = true;
	}
	else
	{
		i = -1;
		reverse = false;
	}
	while (cost->ra != 0)
	{
			ft_call_rotate(&(data->a), NULL, reverse);
			cost->ra += i;
	}
	if (cost->rb < 0)
	{
		i = 1;
		reverse = true;
	}
	else
	{
		i = -1;
		reverse = false;
	}
	while (cost->rb != 0)
	{
		ft_call_rotate(NULL, &(data->b), reverse);
		cost->rb += i;
	}
	ft_call_push(&(data->a), &(data->b), data);
}

void	ft_find_home(t_stack *stack, t_move *cost)
{
	int		next;
	int		prev;
	t_stack	*first;
	
	if (stack == NULL)
		return ;
	first = stack;
	next = 0;
	while (((cost->value > stack->value || cost->value < stack->prev->value) && (stack->prev->value < stack->value)) || ((cost->value > stack->value) && (cost->value < stack->prev->value)))
	{
		stack = stack->next;
		next++;
	}
	prev = 0;
	while (((cost->value > first->value || cost->value < first->prev->value) && (first->prev->value < first->value)) || ((cost->value > first->value) && (cost->value < first->prev->value)))
	{
		first = first->prev;
		prev--;
	}
	cost->ra = ft_return_min_abs(next, prev);
}

void	ft_find_max(t_stack *stack, t_qualities *info, t_move *cost)
{
	int		next;
	int		prev;
	t_stack	*first;

	first = stack;
	next = 0;
	while (stack->value != info->max)
	{
		stack = stack->next;
		next++;
	}
	prev = 0;
	while (first->value != info->max)
	{
		first = first->prev;
		prev--;
	}
	cost->rb = ft_return_min_abs(next, prev);
	cost->value = info->max;
}

void	ft_only_rotate(t_input *data, t_qualities *info, t_move *cost)
{
	int		next;
	int		prev;
	bool	reverse;
	t_stack	*stack;
	t_stack	*first;

	stack = data->a;
	first = stack;
	next = 0;
	while (stack->prev->value != info->max)
	{
		stack = stack->next;
		next++;
	}
	prev = 0;
	while (first->prev->value != info->max)
	{
		first = first->prev;
		prev--;
	}
	cost->ra = ft_return_min_abs(next, prev);
	reverse = false;
	if (cost->ra < 0)
		reverse = true;
	while (data->a->prev->value != info->max)
		ft_call_rotate(&(data->a), NULL, reverse);
}

void	ft_push_imposter(t_input *data, t_qualities *info, t_move *cost)
{
	int		rr;
	int		i;
	bool	reverse;
	size_t	len_a;
	size_t	len_b;

	len_a = info->len;
	len_b = data->item_count - len_a;
	rr = ft_return_min_abs(cost->ra, cost->rb);
	i = -1;
	reverse = false;
	if (rr < 0)
	{
		i = 1;
		reverse = true;
	}
	if (ft_issamesign(cost->ra, cost->rb) == true)
	{
		cost->ra -= rr;
		cost->rb -= rr;
		while (rr != 0)
		{
			ft_call_rotate(&(data->a), &(data->b), reverse);
			rr += i;
		}
		while (cost->ra != 0)
		{
			ft_call_rotate(&(data->a), NULL, reverse);
			cost->ra += i;
		}
		while (cost->rb != 0)
		{
			ft_call_rotate(NULL, &(data->b), reverse);
			cost->rb += i;
		}
	}
	else if (rr == cost->ra)
	{
		if (ft_abs(cost->ra - cost->rb) > (int)len_b / 2)
		{
			if (cost->rb < 0)
				cost->rb += len_b;
			else
				cost->rb -= len_b;
			ft_push_imposter(data, info, cost);
			return ;
		}
	}
	else if (rr == cost->rb)
	{
		if (ft_abs(cost->rb - cost->ra) > (int)len_a / 2)
		{
			if (cost->ra < 0)
				cost->ra += len_a;
			else
				cost->ra -= len_a;
			ft_push_imposter(data, info, cost);
			return ;
		}
	}
	if (cost->ra < 0)
	{
		i = 1;
		reverse = true;
	}
	else
	{
		i = -1;
		reverse = false;
	}
	while (cost->ra != 0)
	{
			ft_call_rotate(&(data->a), NULL, reverse);
			cost->ra += i;
	}
	if (cost->rb < 0)
	{
		i = 1;
		reverse = true;
	}
	else
	{
		i = -1;
		reverse = false;
	}
	while (cost->rb != 0)
	{
		ft_call_rotate(NULL, &(data->b), reverse);
		cost->rb += i;
	}
	ft_call_push(&(data->b), &(data->a), data);
}

void	ft_find_target(t_stack *stack, t_move *cost)
{
	int		next;
	int		prev;
	t_stack	*first;

	if (stack == NULL)
		return ;
	first = stack;
	next = 0;
	while (((cost->value < stack->value || cost->value > stack->prev->value) && (stack->value < stack->prev->value)) || (cost->value < stack->value && cost->value > stack->prev->value))
	{
		stack = stack->next;
		next++;
	}
	prev = 0;
	while (((cost->value < first->value || cost->value > first->prev->value) && (first->value < first->prev->value)) || (cost->value < first->value && cost->value > first->prev->value))
	{
		first = first->prev;
		prev--;
	}
	cost->rb = ft_return_min_abs(next, prev);
}

void	ft_find_imposter(t_stack *stack, t_qualities info, t_move *cost)
{
	int		next;
	int		prev;
	t_stack	*first;

	first = stack;
	next = 0;
	while (stack->value < stack->next->value || stack->value == info.max)
	{
		stack = stack->next;
		next++;
	}
	prev = 0;
	while (first->next->value > first->value || first->value == info.max)
	{
		first = first->prev;
		prev--;
	}
	cost->ra = ft_return_min_abs(next, prev);
	if (cost->ra == next)
		cost->value = stack->value;
	else
		cost->value = first->value;
}

void	ft_big_sort(t_input *data)
{
	t_qualities	info;
	t_move		cost;

	ft_bzero(&info, sizeof(t_qualities));
	ft_bzero(&cost, sizeof(t_move));
	while (ft_isascending(data->a, &info) == false && info.len > 3)
	{
		ft_find_imposter(data->a, info, &cost);
		ft_find_target(data->b, &cost);
		ft_push_imposter(data, &info, &cost);
		ft_bzero(&info, sizeof(t_qualities));
		ft_bzero(&cost, sizeof(t_move));
	}
	if (info.len == 3)
		ft_small_sort(data);
	while (data->b != NULL)
	{
		ft_isascending(data->b, &info);
		ft_find_max(data->b, &info, &cost);
		ft_find_home(data->a, &cost);
		ft_push_home(data, &info, &cost);
	}
	ft_isascending(data->a, &info);
	ft_only_rotate(data, &info, &cost);
}
