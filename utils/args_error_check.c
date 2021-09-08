/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_error_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:43:17 by dwillett          #+#    #+#             */
/*   Updated: 2021/03/04 15:43:18 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sign_check(int *flag, long int num)
{
	if (*flag == 1 && num < 0)
		return (0);
	else if (*flag == -1 && num > 0)
		return (0);
	else if (*flag == 0)
	{
		if (num > 0)
			*flag = 1;
		else if (num < 0)
			*flag = -1;
	}
	return (1);
}

int	doubles_check(t_stack *a, int num)
{
	while (a)
	{
		if (a->content == num)
			return (0);
		a = a->next;
	}
	return (1);
}

int	isnum_check(char *arg)
{
	int i;

	i = 0;
	if (ft_isdigit(arg[i]) == 0)
	{
		if (arg[i] != '-' && arg[i] != '+')
			return (0);
		i++;
	}
	if (arg[i] == '\0')
		return (0);
	while (arg[i] != '\0')
	{
		if (ft_isdigit(arg[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	args_error_check(char **argv, t_stack **a)
{
	int			i;
	static int	sign_flag;
	long int	num;
	t_stack		*tmp;

	i = 1;
	while (argv[i])
	{
		if (isnum_check(argv[i]) == 0)
			return (0);
		num = ft_atoi(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		if (sign_check(&sign_flag, num) == 0)
			return (0);
		if (doubles_check(*a, (int)num) == 0)
			return (0);
		if (!(tmp = ft_lstnew_s((int)num)))
			return (0);
		ft_lstadd_back_s(a, tmp);
		i++;
	}
	return (1);
}
