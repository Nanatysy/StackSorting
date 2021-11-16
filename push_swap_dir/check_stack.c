#include "../push_swap.h"

int	ft_is_it_sorted(t_stack *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

int	find_num(t_stack *tmp, int top, int flag)
{
	while (tmp)
	{
		if (flag)
		{
			if (tmp->content < top)
				return (1);
		}
		else
		{
			if (tmp->content > top)
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	find_max(t_stack *tmp)
{
	int max;

	if (!tmp)
		return (0);
	max = tmp->content;
	while (tmp)
	{
		if (tmp->content > max)
			max = tmp->content;
		tmp = tmp->next;
	}
	return (max);
}

int	find_min(t_stack *tmp)
{
	int min;

	if (!tmp)
		return (0);
	min = tmp->content;
	while (tmp)
	{
		if (tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}
