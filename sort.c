/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 21:47:15 by gde-win           #+#    #+#             */
/*   Updated: 2024/01/10 03:51:51 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_issorted(t_stack *stack)
{
	t_stack	*first;

	first = stack;
	while (stack->next != first)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	ft_big_sort(t_input *data)
{
	ft_call_push(&(data->b), &(data->a), data);
}

void	ft_small_sort(t_input *data)
{
	int		max;
	size_t	index;
	t_stack	*stack;

	stack = data->a;
	max = ft_get_max(stack);
	index = 0;
	while (max != stack->value)
	{
		stack = stack->next;
		index++;
	}
	if (index == 0)
		ft_call_rotate(&(data->a), NULL, false);
	else if (index == 1)
		ft_call_rotate(&(data->a), NULL, true);
	if (ft_issorted(data->a) == false)
		ft_call_swap(&(data->a), NULL);
}

void	ft_sort(t_input *data)
{
	if (data->item_count < 4)
		ft_small_sort(data);
	else
		ft_big_sort(data);
}
