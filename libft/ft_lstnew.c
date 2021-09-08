/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <dwillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:56:23 by dwillett          #+#    #+#             */
/*   Updated: 2020/11/08 17:37:04 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
