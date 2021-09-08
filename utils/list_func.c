/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 17:41:40 by dwillett          #+#    #+#             */
/*   Updated: 2021/03/04 17:41:42 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_lstnew_s(int num)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new)
	{
		new->content = num;
		new->color_flag = 0;
		new->next = NULL;
	}
	return (new);
}

void	ft_lstadd_back_s(t_stack **head, t_stack *new)
{
	t_stack	*tmp;

	if (!head || !new)
		return ;
	if (*head == NULL)
		*head = new;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	ft_lstadd_front_s(t_stack **head, t_stack *new)
{
	if (!new || !head)
		return ;
	new->next = *head;
	*head = new;
}

void	ft_lstclear_s(t_stack **a)
{
	t_stack	*tmp;
	t_stack *next;

	if (a == NULL)
		return ;
	tmp = *a;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*a = NULL;
}

int		ft_lstcount(t_stack *a)
{
	int	count;

	count = 0;
	while (a)
	{
		count++;
		a = a->next;
	}
	return (count);
}
