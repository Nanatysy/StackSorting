/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_second.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 15:04:52 by dwillett          #+#    #+#             */
/*   Updated: 2021/03/18 15:04:53 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	first_quick_sort(t_stack **a, t_stack **b)
{
	int	ref;

	ref = find_median(*a);
	while (find_num(*a, ref, 1))
	{
		if ((*a)->content <= ref)
			call_push(a, b, 0, 1);
		else
			call_rotate(a, b, 0, 1);
	}
}

int		rotate_or_push(t_stack **a, t_stack **b, int ref)
{
	int count;

	count = 0;
	if ((*b)->content <= ref)
		call_rotate(a, b, 1, 1);
	else
	{
		count++;
		call_push(a, b, 1, 1);
	}
	return (count);
}

void	rotate_stack_b(t_stack **a, t_stack **b, int *rotate, int min)
{
	while ((*b)->content != min)
	{
		if (*rotate)
		{
			*rotate = 0;
			call_rotate(a, b, 2, 1);
		}
		else
			call_rotate(a, b, 1, 1);
	}
}

void	rev_rotate_stack_b(t_stack **a, t_stack **b, int *rotate, int min)
{
	if (*rotate)
	{
		*rotate = 0;
		call_rotate(a, b, 0, 1);
	}
	while ((*b)->content != min)
		call_rev_rotate(a, b, 1, 1);
}
