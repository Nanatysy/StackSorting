/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_exec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:50:35 by dwillett          #+#    #+#             */
/*   Updated: 2021/03/04 21:50:37 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_and_push_inst(t_list *inst, t_stack **a, t_stack **b)
{
	if (ft_strncmp(inst->content, "sa", ft_strlen("sa") + 1) == 0)
		swap(a);
	if (ft_strncmp(inst->content, "sb", ft_strlen("sb") + 1) == 0)
		swap(b);
	if (ft_strncmp(inst->content, "ss", ft_strlen("ss") + 1) == 0)
	{
		swap(a);
		swap(b);
	}
	if (ft_strncmp(inst->content, "pa", ft_strlen("pa") + 1) == 0)
		push(b, a);
	if (ft_strncmp(inst->content, "pb", ft_strlen("pb") + 1) == 0)
		push(a, b);
}

void	rotate_inst(t_list **inst, t_stack **a, t_stack **b)
{
	t_list	*tmp;

	tmp = *inst;
	if (ft_strncmp(tmp->content, "ra", ft_strlen("ra") + 1) == 0 && *a)
	{
		if (!(*a = rotate(*a)))
			my_exit(inst, *a, *b);
	}
	if (ft_strncmp(tmp->content, "rb", ft_strlen("rb") + 1) == 0 && *b)
	{
		if (!(*b = rotate(*b)))
			my_exit(inst, *a, *b);
	}
	if (ft_strncmp(tmp->content, "rr", ft_strlen("rr") + 1) == 0)
	{
		if (*a)
			if (!(*a = rotate(*a)))
				my_exit(inst, *a, *b);
		if (*b)
			if (!(*b = rotate(*b)))
				my_exit(inst, *a, *b);
	}
}

void	rev_rotate_inst(t_list **inst, t_stack **a, t_stack **b)
{
	t_list	*tmp;

	tmp = *inst;
	if (ft_strncmp(tmp->content, "rra", ft_strlen("rra") + 1) == 0 && *a)
	{
		if (!(*a = rev_rotate(*a)))
			my_exit(inst, *a, *b);
	}
	if (ft_strncmp(tmp->content, "rrb", ft_strlen("rrb") + 1) == 0 && *b)
	{
		if (!(*b = rev_rotate(*b)))
			my_exit(inst, *a, *b);
	}
	if (ft_strncmp(tmp->content, "rrr", ft_strlen("rrr") + 1) == 0)
	{
		if (*a)
			if (!(*a = rev_rotate(*a)))
				my_exit(inst, *a, *b);
		if (*b)
			if (!(*b = rev_rotate(*b)))
				my_exit(inst, *a, *b);
	}
}

void	instructions_exec(t_list *inst, t_stack **a, t_stack **b)
{
	while (inst)
	{
		swap_and_push_inst(inst, a, b);
		rotate_inst(&inst, a, b);
		rev_rotate_inst(&inst, a, b);
		inst = inst->next;
	}
}
