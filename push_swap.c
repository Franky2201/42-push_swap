/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:05:50 by gde-win           #+#    #+#             */
/*   Updated: 2024/01/16 23:30:06 by gde-win          ###   ########.fr       */
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
	if (data->stack_copy_alloc == true)
		free(data->stack_copy);
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
	if (ft_issorted(data.a) == false)
		ft_sort(&data);
	ft_free_input(&data);
}
