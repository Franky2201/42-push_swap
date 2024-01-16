/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 22:23:24 by gde-win           #+#    #+#             */
/*   Updated: 2024/01/16 23:36:47 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_isunique(t_stack *stack)
{
	t_stack	*i;
	t_stack	*j;

	i = stack;
	while (i != stack->prev)
	{
		j = i->next;
		while (j != stack)
		{
			if (i->value == j->value)
				return (false);
			j = j->next;
		}
		i = i->next;
	}
	return (true);
}

bool	ft_isdigit_and_inbounds(int n, char *nbr0)
{
	char	*nbr1;

	nbr1 = ft_itoa(n);
	if (nbr1 == NULL)
		return (false);
	if (*nbr0 == '+')
		nbr0++;
	n = ft_strcmp(nbr1, nbr0);
	free(nbr1);
	if (n != 0)
		return (false);
	return (true);
}

bool	ft_isint(t_input *data)
{
	size_t	i;
	int		n;
	t_stack	*node;

	i = 0;
	node = data->a;
	while (i < data->item_count)
	{
		n = ft_atoi(data->av_copy[i]);
		if (ft_isdigit_and_inbounds(n, data->av_copy[i]) == false)
			return (false);
		ft_add_to_stack(n, &node, data);
		ft_add_to_copy(n, data->stack_copy, i);
		i++;
	}
	return (true);
}

void	ft_split_arg(char **av, t_input *data)
{
	size_t	i;

	if (av[1][0] == '\0')
		exit(EXIT_SUCCESS);
	data->av_copy = ft_split(av[1], ' ');
	if (data->av_copy == NULL)
		ft_error(data);
	data->av_copy_alloc = true;
	i = 1;
	while (data->av_copy[i] != NULL)
		i++;
	data->item_count = i;
}

void	ft_check_args(int ac, char **av, t_input *data)
{
	if (ac < 2)
		exit(EXIT_SUCCESS);
	if (ac == 2)
		ft_split_arg(av, data);
	else
	{
		data->item_count = ac - 1;
		data->av_copy = av + 1;
	}
	data->stack_copy = (int *)malloc(data->item_count * sizeof(int));
	if (data->stack_copy == NULL)
		ft_error(data);
	data->stack_copy_alloc = true;
	if (ft_isint(data) == false)
		ft_error(data);
	if (ft_isunique(data->a) == false)
		ft_error(data);
	ft_sort_stack_copy(data);
}
