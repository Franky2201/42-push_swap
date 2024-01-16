/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 21:47:15 by gde-win           #+#    #+#             */
/*   Updated: 2024/01/16 23:45:56 by gde-win          ###   ########.fr       */
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

void	ft_small_sort(t_input *data)
{
	size_t	max;

	max = (size_t)ft_max((int)data->a->index, (int)data->a->next->index);
	max = (size_t)ft_max((int)max, (int)data->a->prev->index);
	if (data->a->index == max)
		ft_call_rotate(&(data->a), NULL, false);
	else if (data->a->next->index == max)
		ft_call_rotate(&(data->a), NULL, true);
	if (data->a->index > data->a->next->index)
		ft_call_swap(&(data->a), NULL);
}

void	ft_sort(t_input *data)
{
	if (data->item_count < 4)
		ft_small_sort(data);
	else
		ft_big_sort(data);
}
