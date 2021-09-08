/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:39:56 by dwillett          #+#    #+#             */
/*   Updated: 2021/03/16 18:39:57 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ints_collection_bonus(t_stack **a, t_stack **b, int flag)
{
	t_list	*new;
	char	*line;
	int		i;

	while ((i = get_next_line(&line)) == 1)
	{
		if (!(new = ft_lstnew(ft_strdup(line))))
			exit(0);
		if (instructions_check(&new))
			instructions_exec(new, a, b);
		else
			exit(0);
		print_stack_all(*a, *b, flag);
		down_flag(a, b);
		free(line);
		ft_lstclear(&new, free);
	}
	if ((i == 0 && line[0] != '\0') || i == -1)
		exit(0);
	free(line);
}

int		instructions(t_stack **a, t_stack **b, t_list *inst, t_bonus bonus)
{
	if (bonus.debug)
		ints_collection_bonus(a, b, bonus.color);
	else
	{
		if (inst_collection(&inst) == 0)
			return (error_message(a, NULL));
		instructions_exec(inst, a, b);
		ft_lstclear(&inst, free);
	}
	return (1);
}
