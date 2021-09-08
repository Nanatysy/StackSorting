/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:06:25 by dwillett          #+#    #+#             */
/*   Updated: 2021/03/16 14:06:27 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*copy(t_stack *ref)
{
	t_stack *new;
	t_stack *head;

	head = NULL;
	while (ref)
	{
		if (!(new = ft_lstnew_s(ref->content)))
		{
			ft_lstclear_s(&head);
			ft_putendl_fd("Error", 2);
			exit(0);
		}
		ft_lstadd_back_s(&head, new);
		ref = ref->next;
	}
	return (head);
}
