#include "../push_swap.h"

void	ft_clear(char **tmp)
{
	if (tmp)
	{
		free(tmp[0]);
		free(tmp);
	}
}

int		error_message(t_stack **a, char **tmp)
{
	ft_clear(tmp);
	ft_lstclear_s(a);
	ft_putendl_fd("Error", 2);
	return (0);
}

void	my_exit(t_list **inst, t_stack *a, t_stack *b)
{
	ft_lstclear(inst, free);
	ft_lstclear_s(&a);
	ft_lstclear_s(&b);
	ft_putendl_fd("Error", 2);
	exit(0);
}

int		sort_check(t_stack *a)
{
	int prev;

	if (!a)
		return (0);
	prev = a->content;
	a = a->next;
	while (a)
	{
		if (a->content < prev)
			return (0);
		prev = a->content;
		a = a->next;
	}
	return (1);
}

void	result_output(t_stack **a, t_stack **b, t_list **inst)
{
	ft_lstclear(inst, free);
	if (*b)
	{
		ft_lstclear_s(a);
		ft_lstclear_s(b);
		ft_putendl_fd("KO", 1);
		return ;
	}
	if (sort_check(*a) == 0)
		ft_putendl_fd("KO", 1);
	else
		ft_putendl_fd("OK", 1);
	ft_lstclear_s(a);
}
