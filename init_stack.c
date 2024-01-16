/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:36:13 by gde-win           #+#    #+#             */
/*   Updated: 2024/01/16 00:44:24 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_assign_index_to_nodes(t_input *data)
{
	int		*copy;
	t_stack	*stack;
	size_t	i;

	copy = data->stack_copy;
	stack = data->a;
	i = 0;
	while (i < data->item_count)
	{
		while (stack->value != copy[i])
			stack = stack->next;
		stack->index = i;
		i++;
	}
}

void	ft_sort_stack_copy(t_input *data)
{
	int		*copy;
	size_t	i;
	size_t	j;
	int		temp;

	copy = data->stack_copy;
	i = 0;
	while (i + 1 < data->item_count)
	{
		j = i + 1;
		while (j < data->item_count)
		{
			if (copy[i] > copy[j])
			{
				temp = copy[i];
				copy[i] = copy[j];
				copy[j] = temp;
			}
			j++;
		}
		i++;
	}
	ft_assign_index_to_nodes(data);
}

void	ft_add_to_copy(int value, int *copy, size_t index)
{
	copy[index] = value;
}

void	ft_add_to_stack(int value, t_stack **node, t_input *data)
{
	t_stack	*prev;

	prev = *node;
	*node = (t_stack *)malloc(sizeof(t_stack));
	if (*node == NULL)
		ft_error(data);
	if (data->a == NULL)
		data->a = *node;
	else
		prev->next = *node;
	(*node)->value = value;
	(*node)->next = data->a;
	(*node)->prev = prev;
	data->a->prev = *node;
}
