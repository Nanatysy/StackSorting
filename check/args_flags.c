#include "../push_swap.h"

int		search_for_the_flag(char **argv, int *i)
{
	int res;

	res = 1;
	while (argv[*i] && !(isnum_check(argv[*i])))
	{
		if (!(ft_strncmp(argv[*i], "-v", 3)))
			res += 2;
		else if (!(ft_strncmp(argv[*i], "-c", 3)))
			res += 4;
		else if (!(ft_strncmp(argv[*i], "-vc", 4)) || !(ft_strncmp(argv[*i], \
		"-cv", 4)))
			res += 6;
		else
			return (0);
		*i = *i + 1;
	}
	return (res);
}

void	init_bonus_struct(t_bonus *bonus, int flag)
{
	if (flag & 2)
		bonus->debug = 1;
	else if (bonus->debug != 1)
		bonus->debug = 0;
	if (flag & 4)
		bonus->color = 1;
	else if (bonus->color != 1)
		bonus->color = 0;
}

int		args_error_check_extra(char **argv, t_stack **a, int *sign_flag, int i)
{
	long int	num;
	t_stack		*tmp;

	if (isnum_check(argv[i]) == 0)
		return (0);
	num = ft_atoi(argv[i]);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	if (sign_check(sign_flag, num) == 0)
		return (0);
	if (doubles_check(*a, (int)num) == 0)
		return (0);
	if (!(tmp = ft_lstnew_s((int)num)))
		return (0);
	ft_lstadd_back_s(a, tmp);
	return (1);
}

int		args_error_check_bonus(char **argv, t_stack **a, t_bonus *bonus)
{
	int			flag;
	int			i;
	static int	sign_flag;

	i = 1;
	if ((flag = search_for_the_flag(argv, &i)) == 0)
		return (0);
	init_bonus_struct(bonus, flag);
	while (argv[i])
	{
		if (args_error_check_extra(argv, a, &sign_flag, i) == 0)
			return (0);
		i++;
	}
	return (1);
}
