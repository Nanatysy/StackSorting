#include "../push_swap.h"

t_stack	*copy(t_stack *ref)
{
	t_stack *new;
	t_stack *head;

	head = NULL;
	while (ref)
	{
		if (!(new = ft_lstnew_s(ref->content)))
		{
			ft_lstclear_s(&head);
			ft_putendl_fd("Error", 2);
			exit(0);
		}
		ft_lstadd_back_s(&head, new);
		ref = ref->next;
	}
	return (head);
}
