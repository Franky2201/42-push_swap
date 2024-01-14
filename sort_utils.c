/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 04:31:50 by gde-win           #+#    #+#             */
/*   Updated: 2024/01/12 01:53:08 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_issamesign(int a, int b)
{
	if ((a < 0 && b < 0) || (a >= 0 && b >= 0))
		return (true);
	return (false);
}

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	ft_return_min_abs(int a, int b)
{
	if (ft_abs(a) < ft_abs(b))
		return (a);
	return (b);
}

int	ft_get_max(t_stack *stack)
{
	int		max;
	t_stack	*first;

	first = stack;
	max = stack->value;
	while (stack->next != first)
	{
		if (stack->next->value > max)
			max = stack->next->value;
		stack = stack->next;
	}
	return (max);
}

void	ft_get_max_pointer(t_stack *stack, t_qualities *info)
{
	info->max = ft_get_max(stack);
	info->position = 1;
	while (info->max != stack->value)
	{
		stack = stack->next;
		info->position++;
	}
	info->max_pointer = stack;
}

bool	ft_isascending(t_stack *stack, t_qualities *info)
{
	t_stack		*first;

	info->ascending = true;
	if (stack == NULL)
		return (true);
	ft_get_max_pointer(stack, info);
	first = info->max_pointer->next;
	stack = first;
	info->len = 1;
	while (stack->next != first)
	{
		if (stack->value > stack->next->value)
			info->ascending = false;
		stack = stack->next;
		info->len++;
	}
	return (info->ascending);
}
