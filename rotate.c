/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 00:28:20 by gde-win           #+#    #+#             */
/*   Updated: 2024/01/10 03:53:14 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_rotate(char c)
{
	if (c != 'a' && c != 'b')
		c = 'r';
	ft_printf("r%c\n", c);
}

void	ft_do_rotate(t_stack **stack, bool reverse)
{
	if (reverse == false)
		*stack = (*stack)->next;
	else
		*stack = (*stack)->prev;
}

void	ft_call_rotate(t_stack **a, t_stack **b, bool reverse)
{
	char	flag;

	flag = 0;
	if (a != NULL)
	{
		ft_do_rotate(a, reverse);
		flag += 'a';
	}
	if (b != NULL)
	{
		ft_do_rotate(b, reverse);
		flag += 'b';
	}
	if (reverse == true)
		ft_printf("r");
	ft_print_rotate(flag);
}
