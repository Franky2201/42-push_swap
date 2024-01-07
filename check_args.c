/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 22:23:24 by gde-win           #+#    #+#             */
/*   Updated: 2024/01/07 01:04:05 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_isunique(t_stack *list)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i + 1 < list->item_count)
	{
		j = i + 1;
		while (j < list->item_count)
		{
			if (list->stack_A[i] == list->stack_A[j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	ft_isinbounds(int n, char *nbr0)
{
	char	*nbr1;

	nbr1 = ft_itoa(n);
	if (*nbr0 == '+')
		nbr0++;
	n = ft_strcmp(nbr1, nbr0);
	free(nbr1);
	if (n != 0)
		return (false);
	return (true);
}

bool	ft_isint(t_stack *list)
{
	size_t	i;
	size_t	j;
	int		n;

	i = 0;
	while (i < list->item_count)
	{
		j = 0;
		n = ft_atoi(list->av_copy[i]);
		if (ft_isinbounds(n, list->av_copy[i]) == false)
			return (false);
		if ((list->av_copy[i][j] == '+' || list->av_copy[i][j] == '-') \
				&& list->av_copy[i][j + 1] != '\0')
			j++;
		while (list->av_copy[i][j] != '\0')
		{
			if (ft_isdigit(list->av_copy[i][j]) == 0)
				return (false);
			j++;
		}
		list->stack_A[i] = n;
		i++;
	}
	return (true);
}

void	ft_check_args(int *ac, char ***av, t_parsed_list *list)
{
	if (*ac < 2)
		exit(EXIT_SUCCESS);
	if (*ac == 2)
		ft_split_arg(av, list);
	else
	{
		list->item_count = *ac - 1;
		list->av_copy = *av + 1;
	}
	ft_malloc_stack(list);
	if (ft_isint(list) == false)
		ft_error(*list);
	if (ft_isunique(list) == false)
		ft_error(*list);
}
