#include "../push_swap.h"

int	find_placement(t_stack *tmp, int ref)
{
	int count;

	count = 0;
	while (tmp->content < ref)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

int	five_sort_extra(t_stack **a, t_stack **b, int print)
{
	int res;
	int count;

	res = 0;
	count = find_placement(*a, (*b)->content);
	if ((ft_lstcount(*a) - count) > 1)
	{
		while ((*a)->content < (*b)->content)
			res += call_rotate(a, b, 0, print);
		res += call_push(a, b, 1, print);
		while (count-- > 0)
			res += call_rev_rotate(a, b, 0, print);
	}
	else
	{
		res += call_rev_rotate(a, b, 0, print);
		res += call_push(a, b, 1, print);
		res += call_rotate(a, b, 0, print);
		res += call_rotate(a, b, 0, print);
	}
	return (res);
}

int	five_sort(t_stack *a, t_stack *b, int print)
{
	int		res;

	res = 0;
	res += call_push(&a, &b, 0, print);
	res += call_push(&a, &b, 0, print);
	res += sort_three(&a, print);
	while (b)
	{
		if (b->content > find_max(a))
		{
			res += call_push(&a, &b, 1, print);
			res += call_rotate(&a, &b, 0, print);
		}
		else
			res += five_sort_extra(&a, &b, print);
	}
	call_for_clear(a, b);
	return (res);
}
