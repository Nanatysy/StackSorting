/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_collection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:59:18 by dwillett          #+#    #+#             */
/*   Updated: 2021/03/16 16:59:20 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	arg_collection(char **argv, t_stack **a)
{
	char	**tmp;
	int		i;

	i = 1;
	while (argv[i])
	{
		if (!(tmp = ft_split(argv[i], ' ')))
			return (error_message(a, tmp));
		if (args_error_check(tmp, a) == 0)
			return (error_message(a, tmp));
		free(tmp[0]);
		free(tmp);
		i++;
	}
	return (1);
}
