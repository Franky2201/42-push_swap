/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:05:50 by gde-win           #+#    #+#             */
/*   Updated: 2024/01/10 03:48:20 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack *stack)
{
	t_stack	*last;

	if (stack == NULL)
		return ;
	last = stack->prev;
	while (stack != last)
	{
		stack = stack->next;
		free(stack->prev);
	}
	free(last);
}

void	ft_free_input(t_input *data)
{
	size_t	i;

	ft_free_stack(data->a);
	ft_free_stack(data->b);
	if (data->av_copy_alloc == true)
	{
		i = 0;
		while (data->av_copy[i] != NULL)
		{
			free(data->av_copy[i]);
			i++;
		}
		free(data->av_copy);
	}
}

void	ft_error(t_input *data)
{
	ft_free_input(data);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_input	data;

	ft_bzero(&data, sizeof(t_input));
	ft_check_args(ac, av, &data);
	size_t	i = 0;
/*	while (i < 3)
	{
		ft_printf("add: %p\nn: %p\np: %p\n%i\n\n", data.A, data.A->next, data.A->prev, data.A->value);
		data.A = data.A->next;
		i++;
	}
	ft_call_push(&data.B, &data.A, &data);
*/	while (ft_issorted(data.a) == false)
	{
		ft_sort(&data);
	}
	i = 0;
	ft_printf("A:---------------------------------\n");
	while (i < 3)
	{
		ft_printf("add: %p\nn: %p\np: %p\n%i\n\n", data.a, data.a->next, data.a->prev, data.a->value);
		data.a = data.a->next;
		i++;
	}
	i = 0;
	ft_printf("B:---------------------------------\n");
	while (i < 3)
	{
		ft_printf("add: %p\nn: %p\np: %p\n%i\n\n", data.b, data.b->next, data.b->prev, data.b->value);
		data.b = data.b->next;
		i++;
	}
	ft_free_input(&data);
}
