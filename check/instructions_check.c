/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_check.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 17:41:30 by dwillett          #+#    #+#             */
/*   Updated: 2021/03/04 17:41:33 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_str(char *str)
{
	if (ft_strncmp(str, "sa", ft_strlen("sa") + 1) == 0)
		return (1);
	if (ft_strncmp(str, "sb", ft_strlen("sb") + 1) == 0)
		return (1);
	if (ft_strncmp(str, "ss", ft_strlen("ss") + 1) == 0)
		return (1);
	if (ft_strncmp(str, "pa", ft_strlen("pa") + 1) == 0)
		return (1);
	if (ft_strncmp(str, "pb", ft_strlen("pb") + 1) == 0)
		return (1);
	if (ft_strncmp(str, "ra", ft_strlen("ra") + 1) == 0)
		return (1);
	if (ft_strncmp(str, "rb", ft_strlen("rb") + 1) == 0)
		return (1);
	if (ft_strncmp(str, "rr", ft_strlen("rr") + 1) == 0)
		return (1);
	if (ft_strncmp(str, "rra", ft_strlen("rra") + 1) == 0)
		return (1);
	if (ft_strncmp(str, "rrb", ft_strlen("rrb") + 1) == 0)
		return (1);
	if (ft_strncmp(str, "rrr", ft_strlen("rrr") + 1) == 0)
		return (1);
	return (0);
}

int	instructions_check(t_list **inst)
{
	t_list	*tmp;

	tmp = *inst;
	while (tmp)
	{
		if (check_str(tmp->content) == 0)
		{
			ft_lstclear(inst, free);
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

int	gnl_clear(char *line, t_list **inst)
{
	if (line)
		free(line);
	ft_lstclear(inst, free);
	return (0);
}

int	inst_collection(t_list **inst)
{
	int		i;
	char	*line;
	t_list	*new;

	while ((i = get_next_line(&line)) == 1)
	{
		if (!(new = ft_lstnew(ft_strdup(line))))
			return (gnl_clear(line, inst));
		ft_lstadd_back(inst, new);
		free(line);
	}
	if (i == -1)
		return (gnl_clear(line, inst));
	if (i == 0 && line[0] != '\0')
		return (gnl_clear(line, inst));
	free(line);
	return (instructions_check(inst));
}
