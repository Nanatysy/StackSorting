/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 19:37:22 by dwillett          #+#    #+#             */
/*   Updated: 2021/03/04 19:37:23 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **current)
{
	t_stack	*tmp;

	if (!current)
		return ;
	tmp = *current;
	if (tmp && tmp->next)
	{
		tmp->content = tmp->content + tmp->next->content;
		tmp->next->content = tmp->content - tmp->next->content;
		tmp->content = tmp->content - tmp->next->content;
		tmp->color_flag = 1;
		tmp->next->color_flag = 1;
	}
}

t_stack	*rev_rotate(t_stack *current)
{
	t_stack	*tmp;
	t_stack	*prev_tmp;
	t_stack	*new;
	int		num;

	if (ft_lstcount(current) < 2)
		return (current);
	tmp = current;
	while (tmp->next)
	{
		prev_tmp = tmp;
		tmp = tmp->next;
	}
	num = tmp->content;
	if (!(new = ft_lstnew_s(num)))
	{
		ft_lstclear_s(&current);
		return (NULL);
	}
	ft_lstadd_front_s(&current, new);
	new->color_flag = 1;
	prev_tmp->next = NULL;
	free(tmp);
	return (new);
}

t_stack	*rotate(t_stack *current)
{
	t_stack	*tmp;
	t_stack	*new;
	int		num;

	if (ft_lstcount(current) < 2)
		return (current);
	num = current->content;
	tmp = current->next;
	if (!(new = ft_lstnew_s(num)))
	{
		ft_lstclear_s(&current);
		return (NULL);
	}
	new->color_flag = 1;
	ft_lstadd_back_s(&current, new);
	free(current);
	return (tmp);
}

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (*src)
	{
		tmp = *src;
		tmp->color_flag = 1;
		tmp = tmp->next;
		ft_lstadd_front_s(dest, *src);
		*dest = *src;
		*src = tmp;
	}
}
