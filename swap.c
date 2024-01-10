/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 23:02:43 by gde-win           #+#    #+#             */
/*   Updated: 2024/01/10 03:52:27 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_swap(char c)
{
	if (c != 'a' && c != 'b')
		c = 's';
	ft_printf("s%c\n", c);
}

void	ft_do_swap(t_stack **stack)
{
	t_stack	*node;
	t_stack	*temp;

	node = *stack;
	*stack = node->next;
	node->prev->next = node->next;
	node->next->next->prev = node;
	node->next->prev = node->prev;
	node->prev = node->next;
	temp = node->next->next;
	node->next->next = node;
	node->next = temp;
}

void	ft_call_swap(t_stack **a, t_stack **b)
{
	char	flag;

	flag = 0;
	if (a != NULL)
	{
		ft_do_swap(a);
		flag += 'a';
	}
	if (b != NULL)
	{
		ft_do_swap(b);
		flag += 'b';
	}
	ft_print_swap(flag);
}
