/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 02:04:20 by gde-win           #+#    #+#             */
/*   Updated: 2024/01/14 04:38:14 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_push(char c)
{
	ft_printf("p%c\n", c);
}

void	ft_remove_node(t_stack **stack)
{
	t_stack	*node;

	node = *stack;
	if (node->next == node)
		*stack = NULL;
	else
	{
		*stack = node->next;
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
}

void	ft_do_push(t_stack **dst, t_stack **src)
{
	t_stack	*node;
	t_stack	*temp;

	node = *src;
	ft_remove_node(src);
	if (*dst == NULL)
	{
		node->next = node;
		node->prev = node;
	}
	else
	{
		temp = (*dst)->prev;
		(*dst)->prev->next = node;
		(*dst)->prev = node;
		node->prev = temp;
		node->next = *dst;
	}
	*dst = node;
}

void	ft_call_push(t_stack **dst, t_stack **src, t_input *data)
{
	char	flag;

	if (*dst == data->a)
	{
		ft_do_push(dst, src);
		flag = 'a';
	}
	else
	{
		ft_do_push(dst, src);
		flag = 'b';
	}
	ft_print_push(flag);
}
