/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:06:07 by dwillett          #+#    #+#             */
/*   Updated: 2021/03/16 14:06:09 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	call_swap(t_stack **a, t_stack **b, int flag, int print)
{
	if (flag == 0)
	{
		if (print)
			ft_putendl_fd("sa", 1);
		swap(a);
	}
	else if (flag == 1)
	{
		if (print)
			ft_putendl_fd("sb", 1);
		swap(b);
	}
	return (1);
}

int	call_push(t_stack **a, t_stack **b, int flag, int print)
{
	if (print)
		flag ? ft_putendl_fd("pa", 1) : ft_putendl_fd("pb", 1);
	flag ? push(b, a) : push(a, b);
	return (1);
}

int	call_rotate(t_stack **a, t_stack **b, int flag, int print)
{
	if (flag == 0)
	{
		if (print)
			ft_putendl_fd("ra", 1);
		*a = rotate(*a);
	}
	else if (flag == 1)
	{
		if (print)
			ft_putendl_fd("rb", 1);
		*b = rotate(*b);
	}
	else if (flag == 2)
	{
		if (print)
			ft_putendl_fd("rr", 1);
		*a = rotate(*a);
		*b = rotate(*b);
	}
	return (1);
}

int	call_rev_rotate(t_stack **a, t_stack **b, int flag, int print)
{
	if (flag == 0)
	{
		if (print)
			ft_putendl_fd("rra", 1);
		*a = rev_rotate(*a);
	}
	else if (flag == 1)
	{
		if (print)
			ft_putendl_fd("rrb", 1);
		*b = rev_rotate(*b);
	}
	return (1);
}
