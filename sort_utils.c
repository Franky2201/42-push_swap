/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 04:31:50 by gde-win           #+#    #+#             */
/*   Updated: 2024/01/17 00:08:31 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_only_rotate(t_input *data, size_t len)
{
	bool	flag;

	flag = false;
	if (data->a->index < len / 2)
		flag = true;
	while (data->a->index != 0)
		ft_call_rotate(&(data->a), NULL, flag);
}

void	ft_reset_costs(t_stack *stack, size_t len_a, size_t len_b)
{
	size_t	i;

	i = 0;
	while (i < len_b)
	{
		stack->cost.total = INT_MAX;
		stack->cost.ra = len_a;
		stack->cost.rb = len_b;
		stack->cost.rra = len_a;
		stack->cost.rrb = len_b;
		stack = stack->next;
		i++;
	}
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

size_t	ft_stacklen(t_stack *stack, size_t *len)
{
	t_stack	*last;

	*len = 0;
	if (stack == NULL)
		return (*len);
	last = stack->prev;
	*len = 1;
	while (stack != last)
	{
		stack = stack->next;
		(*len)++;
	}
	return (*len);
}

bool	ft_isascending(t_stack *stack)
{
	t_stack	*last;

	if (stack == NULL)
		return (true);
	last = stack->prev;
	while (stack != last)
	{
		if (stack->index + 1 != stack->next->index && stack->next->index != 0)
			return (false);
		stack = stack->next;
	}
	return (true);
}
