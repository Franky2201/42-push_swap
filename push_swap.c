/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:05:50 by gde-win           #+#    #+#             */
/*   Updated: 2024/01/07 00:56:19 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack list)
{
	size_t	i;

	if (list.stack_alloc == true)
	{
		free(list.stack_A);
		free(list.stack_B);
	}
	if (list.av_copy_alloc == true)
	{
		i = 0;
		while (list.av_copy[i] != NULL)
		{
			free(list.av_copy[i]);
			i++;
		}
		free(list.av_copy);
	}
}

void	ft_error(t_stack list)
{
	ft_free(list);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_parsed_list	list;

	ft_bzero(&list, sizeof(t_parsed_list));
	ft_check_args(&ac, &av, &list);
	while (ft_issorted(list.stack_A, list.item_count) == false)
	{
		ft_sort(&list);
	}
	ft_free(list);
}
