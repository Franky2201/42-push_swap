/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:36:13 by gde-win           #+#    #+#             */
/*   Updated: 2024/01/07 01:21:37 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_item(int value, t_stack *prev)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = prev;
	return (node);
}

void	ft_malloc_stack(t_stack *list)
{
	list->stack_A = (int *)malloc(list->item_count * sizeof(int));
	if (list->stack_A == NULL)
		ft_error(*list);
	list->stack_B = (int *)malloc(list->item_count * sizeof(int));
	if (list->stack_B == NULL)
	{
		free(list->stack_A);
		ft_error(*list);
	}
	list->stack_alloc = true;
}

void	ft_split_arg(char ***av, t_parsed_list *list)
{
	size_t	i;

	i = 1;
	list->av_copy = ft_split((*av)[1], ' ');
	if (list->av_copy == NULL)
		ft_error(*list);
	list->av_copy_alloc = true;
	while (list->av_copy[i] != NULL)
		i++;
	list->item_count = i;
}
