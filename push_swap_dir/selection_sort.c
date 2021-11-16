#include "../push_swap.h"

int	find_spec_number(t_stack *a, int ref)
{
	int count;

	count = 1;
	while (a)
	{
		if (a->content == ref)
			return (count);
		a = a->next;
		count++;
	}
	return (count);
}

int	selection_sort_find_min(t_stack **a, t_stack **b, int min, int print)
{
	int res;
	int count;

	res = 0;
	while ((*a)->content != min)
	{
		count = 0;
		while ((*a)->next->content != min)
		{
			res += call_push(a, b, 0, print);
			count++;
		}
		res += call_swap(a, b, 0, print);
		while (count-- > 0)
		{
			res += call_push(a, b, 1, print);
			res += call_swap(a, b, 0, print);
		}
	}
	return (res);
}

int	selection_sort_push_min(t_stack **a, t_stack **b, int *min, int print)
{
	int res;

	res = 0;
	*min = find_min(*a);
	while ((*a)->content == *min)
	{
		res += call_push(a, b, 0, print);
		*min = find_min(*a);
	}
	return (res);
}

int	selection_sort(t_stack *a, t_stack *b, int print)
{
	int min;
	int location;
	int size;
	int res;

	res = 0;
	while (!ft_is_it_sorted(a))
	{
		res += selection_sort_push_min(&a, &b, &min, print);
		size = ft_lstcount(a);
		location = find_spec_number(a, min);
		if (size - location < size / 2)
		{
			while (location++ <= size)
				res += call_rev_rotate(&a, &b, 0, print);
		}
		else
			res += selection_sort_find_min(&a, &b, min, print);
	}
	while (b)
		res += call_push(&a, &b, 1, print);
	call_for_clear(a, b);
	return (res);
}
