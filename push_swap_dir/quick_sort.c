#include "../push_swap.h"

void	rev_select_sort(t_stack **a, t_stack **b)
{
	int min;
	int location;
	int size;
	int rotate;

	rotate = 0;
	while (*b)
	{
		min = find_min(*b);
		size = ft_lstcount(*b);
		if ((*b)->content != min)
		{
			location = find_spec_number(*b, min);
			if (size - location < location - 1 && ft_lstcount(*b) > 2)
				rev_rotate_stack_b(a, b, &rotate, min);
			else
				rotate_stack_b(a, b, &rotate, min);
		}
		if (rotate == 1)
			call_rotate(a, b, 0, 1);
		call_push(a, b, 1, 1);
		rotate = 1;
	}
	if (rotate)
		call_rotate(a, b, 0, 1);
}

int		rev_quick_sort(t_stack **a, t_stack **b, int *flag)
{
	int ref;
	int count;
	int local_min;

	if (ft_lstcount(*b) < 20)
		return (0);
	ref = find_median(*b);
	count = 0;
	while (find_num(*b, ref, 0))
	{
		if (*flag == 1)
			local_min = find_next_value(*a, *b);
		else
			local_min = find_min(*b);
		if ((*b)->content == local_min)
		{
			call_push(a, b, 1, 1);
			call_rotate(a, b, 0, 1);
			*flag = 1;
		}
		else
			count += rotate_or_push(a, b, ref);
	}
	quick_sort_extra(a, b, *flag);
	return (count);
}

void	quick_sort_extra(t_stack **a, t_stack **b, int flag)
{
	int tmp;
	int next;

	tmp = rev_quick_sort(a, b, &flag);
	next = find_next_value(*a, *b);
	while (tmp != 0)
	{
		while (tmp-- > 0)
		{
			if ((*a)->content == next)
			{
				call_rotate(a, b, 0, 1);
				next = find_next_value(*a, *b);
			}
			else
				call_push(a, b, 0, 1);
		}
		tmp = rev_quick_sort(a, b, &flag);
	}
	rev_select_sort(a, b);
}

int		find_next_value(t_stack *a, t_stack *b)
{
	int	last;
	int local_min;

	last = lst_last_content(a);
	local_min = a->content;
	while (a)
	{
		if (a->content < local_min && a->content > last)
			local_min = a->content;
		a = a->next;
	}
	while (b)
	{
		if (b->content < local_min && b->content > last)
			local_min = b->content;
		b = b->next;
	}
	return (local_min);
}

void	quick_sort(t_stack *a, t_stack *b)
{
	int next;
	int	tmp;

	first_quick_sort(&a, &b);
	quick_sort_extra(&a, &b, 0);
	tmp = find_min(a);
	next = find_next_value(a, b);
	while (a->content != tmp)
	{
		if (a->content == next)
		{
			call_rotate(&a, &b, 0, 1);
			next = find_next_value(a, b);
		}
		else
			call_push(&a, &b, 0, 1);
	}
	quick_sort_extra(&a, &b, 1);
	if (b)
		ft_lstclear_s(&b);
	if (a)
		ft_lstclear_s(&a);
}
