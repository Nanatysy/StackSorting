#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	if (content == NULL)
		return (NULL);
	new = (t_list*)malloc(sizeof(t_list) * 1);
	if (new)
	{
		new->content = content;
		new->next = NULL;
		return (new);
	}
	return (NULL);
}
