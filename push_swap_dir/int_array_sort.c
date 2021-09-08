/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_array_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 18:01:24 by dwillett          #+#    #+#             */
/*   Updated: 2021/03/13 18:01:26 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		is_sort_check(int *array, int start, int size)
{
	while (start < size)
	{
		if (array[start] > array[start + 1])
			return (0);
		start++;
	}
	return (1);
}

void	chang_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	tmp_sort(int **array, int size, int start)
{
	int i;
	int j;
	int p;
	int *tmp;

	tmp = *array;
	i = start;
	j = start + size - 1;
	p = tmp[start + (size / 2)];
	while (i < j)
	{
		while (i < (size + start) && tmp[i] < p)
			i++;
		while (j >= start && tmp[j] > p)
			j--;
		if (j > i)
			chang_int(&tmp[i], &tmp[j]);
	}
	if (is_sort_check(tmp, start, (start + size)))
		return ;
	if (j > start + 1)
		tmp_sort(array, j, 0);
	if (size + start > i + 1)
		tmp_sort(array, start + size - i, i);
}

int		find_median(t_stack *tmp)
{
	int	size;
	int i;
	int *array;

	size = ft_lstcount(tmp);
	if (!(array = malloc(sizeof(int) * size)))
		return (0);
	i = 0;
	while (tmp)
	{
		array[i++] = tmp->content;
		tmp = tmp->next;
	}
	tmp_sort(&array, size, 0);
	i = array[size / 2];
	free(array);
	return (i);
}
