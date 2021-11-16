#include "../push_swap.h"

int	bubble_sort_extra(t_stack **a, t_stack **b, t_stack **second, t_trash t)
{
	int		res;
	t_stack	*tmp;

	res = 0;
	if ((*second)->next)
	{
		if (t.top)
			res += call_swap(a, b, 0, t.print);
		else
		{
			while ((*a)->content > (*second)->content)
			{
				tmp = *a;
				while ((*a)->next != (*second))
					res += call_push(a, b, 0, t.print);
				res += call_swap(a, b, 0, t.print);
				*second = *a;
				while (*a != tmp)
					res += call_push(a, b, 1, t.print);
			}
		}
	}
	else
		res += call_rev_rotate(a, b, 0, t.print);
	return (res);
}

int	bubble_sort(t_stack *a, t_stack *b, int print)
{
	t_stack	*second;
	t_trash t;
	int		res;

	res = 0;
	t.top = 1;
	t.print = print;
	while (!(ft_is_it_sorted(a)))
	{
		second = a->next;
		while (second)
		{
			if (a->content > second->content)
				res += bubble_sort_extra(&a, &b, &second, t);
			second = second->next;
			t.top = 0;
		}
		res += call_push(&a, &b, 0, print);
		t.top = 1;
	}
	while (b)
		res += call_push(&a, &b, 1, print);
	call_for_clear(a, b);
	return (res);
}
