/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:41:07 by gde-win           #+#    #+#             */
/*   Updated: 2024/01/10 23:02:58 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	()

void	ft_big_sort(t_input *data)
{
	t_qualities	info_a;
	t_qualities	info_b;
	bool		reverse;

	ft_get_qualities(data->a, &info_a);
	if (info_a.ascending == true)
	{
		reverse = false;
		if (info_a.position > info_a.len / 2)
			reverse = true;
		while (data->a->prev != info_a.max_pointer)
			ft_call_rotate(&(data->a), NULL, reverse);
	}
	if (data->b == NULL)
	{
		ft_call_push(&(data->b), &(data->a), data);
		ft_call_push(&(data->b), &(data->a), data);
	}
	ft_get_qualities(data->a, &info_a);
	ft_get_qualities(data->b, &info_b);
	if (info_a.ascending == true || info_b.descending == true)
	{
		if (info_a.ascending == true && info_b.descending == true)
		{
			if (info_a.position >= info_a.len / 2 && info_b.position >= info_b.len / 2)
			{
				reverse = true;
				
			}
			if (info_a.position <= info_a.len / 2 && info_b.position <= info_b.len / 2)
				reverse = false;
		}
	}
}
