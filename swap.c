/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 23:02:43 by gde-win           #+#    #+#             */
/*   Updated: 2024/01/06 23:48:35 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_swap(char c)
{
	if (c != 'a' && c != 'b')
		c = 's';
	ft_printf("s%c\n", c);
}

void	ft_do_swap(int *stack)
{
	int	temp;

	temp = *stack;
	*stack = *(stack + 1);
	*(stack + 1) = temp;
}

void	ft_call_swap(int *stack_A, int *stack_B)
{
	char	flag;

	flag = 0;
	if (stack_A)
	{
		ft_do_swap(stack_A);
		flag += 'a';
	}
	if (stack_B)
	{
		ft_do_swap(stack_B);
		flag += 'b';
	}
	ft_print_swap(flag);
}
