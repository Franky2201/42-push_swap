/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 04:31:50 by gde-win           #+#    #+#             */
/*   Updated: 2024/01/10 23:31:36 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	info->descending = true;
	if (*stack == NULL)
		return ;
	ft_get_max_pointer(stack, info);
	first = info->max_pointer->next;
	stack = first;
	info->len = 1;
	while (stack->next != first)
	{
		if (stack->value > stack->next->value)
			info->ascending = false;
		if (stack->prev->value < stack->value)
			info->descending = false;
		stack = stack->next;
		info->len++;
	}
}
