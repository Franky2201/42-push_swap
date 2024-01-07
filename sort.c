/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 21:47:15 by gde-win           #+#    #+#             */
/*   Updated: 2024/01/07 00:27:24 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_issorted(int *stack, size_t size)
{
	size_t	i;

	i = 0;
	while (i + 1 < size)
	{
		if (stack[i] > stack[i + 1])
			return (false);
	}
	return (true);
}

void	ft_small_sort(t_stack *list)
{
	ft_call_swap(list->stack_A, NULL);
	if (ft_issorted(list->stack_A, list->item_count) == false)
		ft_call_rotate(list->stack_A, NULL, list->item_count);
	if (ft_issorted(list->stack_A, list->item_count) == false)
		ft_call_swap(list->stack_A, NULL);
}

void	ft_sort(t_stack *list)
{
	if (list->item_count < 4)
		ft_small_sort(list);
	else
		ft_big_sort(list);
}
