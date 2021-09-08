/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:37:46 by dwillett          #+#    #+#             */
/*   Updated: 2021/03/04 15:37:48 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_list	*inst;
	char	**tmp;

	if (argc != 1)
	{
		a = NULL;
		b = NULL;
		inst = NULL;
		while (*(++argv))
		{
			if (!(tmp = ft_split(*argv, ' ')))
				return (error_message(&a, tmp));
			if (args_error_check(tmp, &a) <= 0)
				return (error_message(&a, tmp));
			free(tmp[0]);
			free(tmp);
		}
		if (inst_collection(&inst) == 0)
			return (error_message(&a, NULL));
		instructions_exec(inst, &a, &b);
		result_output(&a, &b, &inst);
	}
	return (0);
}
