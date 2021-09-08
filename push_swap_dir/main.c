/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:00:12 by dwillett          #+#    #+#             */
/*   Updated: 2021/03/04 15:00:18 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	a = NULL;
	b = NULL;
	if (arg_collection(argv, &a) == 0)
		return (0);
	if (ft_is_it_sorted(a))
		return (0);
	choose_sort(a, b);
	return (0);
}
