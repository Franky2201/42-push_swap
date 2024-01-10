/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:36:13 by gde-win           #+#    #+#             */
/*   Updated: 2024/01/10 21:23:37 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
