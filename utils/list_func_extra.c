#include "../push_swap.h"

void	call_for_clear(t_stack *a, t_stack *b)
{
	if (a)
		ft_lstclear_s(&a);
	if (b)
		ft_lstclear_s(&b);
}

int		lst_last_content(t_stack *tmp)
{
	if (!tmp)
		return (0);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->content);
}
