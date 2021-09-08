/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaker_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 18:03:04 by dwillett          #+#    #+#             */
/*   Updated: 2021/03/13 18:03:06 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	shaker_sort(t_stack *a, t_stack *b, int print)
{
	int res;

	res = 0;
	while (!ft_is_it_sorted(a))
	{
		while (a->next && !(ft_is_it_sorted(a)))
		{
			if (a->content > a->next->content)
			{
				res += call_swap(&a, &b, 0, print);
			}
			res += call_push(&a, &b, 0, print);
		}
		while (b)
		{
			res += call_push(&a, &b, 1, print);
			if (a->content > a->next->content)
				res += call_swap(&a, &b, 0, print);
		}
	}
	call_for_clear(a, b);
	return (res);
}
