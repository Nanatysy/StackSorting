/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:05:28 by dwillett          #+#    #+#             */
/*   Updated: 2021/03/16 14:05:30 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		find_index(int array[4])
{
	int i;
	int min;
	int	index;

	i = 0;
	index = 0;
	min = array[i];
	while (++i < 4)
	{
		if (array[i] < min)
		{
			index = i;
			min = array[i];
		}
	}
	return (index);
}

void	small_sorts(t_stack *a, t_stack *b)
{
	int res_sort[4];
	int (*sorts[4]) (t_stack *a, t_stack *b, int print);

	res_sort[0] = bubble_sort(copy(a), b, 0);
	res_sort[1] = shaker_sort(copy(a), b, 0);
	res_sort[2] = selection_sort(copy(a), b, 0);
	if (ft_lstcount(a) == 5)
		res_sort[3] = five_sort(copy(a), b, 0);
	else
		res_sort[3] = INT_MAX;
	sorts[0] = bubble_sort;
	sorts[1] = shaker_sort;
	sorts[2] = selection_sort;
	sorts[3] = five_sort;
	sorts[find_index(res_sort)](a, b, 1);
}

void	choose_sort(t_stack *a, t_stack *b)
{
	if (ft_lstcount(a) >= 20)
		quick_sort(a, b);
	else if (ft_lstcount(a) == 3)
	{
		sort_three(&a, 1);
		ft_lstclear_s(&a);
	}
	else
		small_sorts(a, b);
}
