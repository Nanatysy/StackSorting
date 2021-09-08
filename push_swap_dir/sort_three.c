/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:07:15 by dwillett          #+#    #+#             */
/*   Updated: 2021/03/16 14:07:17 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sort_three_extra(t_stack **a, int print)
{
	int		res;
	t_stack *second;
	t_stack *third;

	res = 0;
	second = (*a)->next;
	third = second->next;
	if ((*a)->content < third->content)
		res += call_swap(a, NULL, 0, print);
	else
	{
		if (second->content > third->content)
		{
			res += call_swap(a, NULL, 0, print);
			res += call_rev_rotate(a, NULL, 0, print);
		}
		else
			res += call_rotate(a, NULL, 0, print);
	}
	return (res);
}

int	sort_three(t_stack **a, int print)
{
	int		res;
	t_stack *second;
	t_stack *third;

	if (ft_is_it_sorted(*a))
		return (0);
	res = 0;
	second = (*a)->next;
	third = second->next;
	if ((*a)->content < second->content)
	{
		if ((*a)->content > third->content)
			res += call_rev_rotate(a, NULL, 0, print);
		else
		{
			res += call_rev_rotate(a, NULL, 0, print);
			res += call_swap(a, NULL, 0, print);
		}
	}
	else
		res += sort_three_extra(a, print);
	return (res);
}
