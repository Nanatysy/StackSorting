#include "../push_swap.h"

void	down_flag(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (a)
	{
		tmp = *a;
		while (tmp)
		{
			tmp->color_flag = 0;
			tmp = tmp->next;
		}
	}
	if (b)
	{
		tmp = *b;
		while (tmp)
		{
			tmp->color_flag = 0;
			tmp = tmp->next;
		}
	}
}

void	ft_putnbr_fd_color(int n, int fd)
{
	char			tmp[11];
	int				i;
	int				flag;
	unsigned int	new;

	i = 0;
	flag = (n < 0) ? 1 : 0;
	new = (flag == 1) ? -n : n;
	write(fd, "\x1b[94m", 5);
	if (new)
	{
		while (new)
		{
			tmp[i++] = (char)((new % 10) + '0');
			new /= 10;
		}
		if (flag == 1)
			tmp[i++] = '-';
		while (i > 0)
			write(fd, &tmp[--i], 1);
	}
	else
		write(fd, "0", 1);
	write(fd, "\x1b[0m", 5);
}

void	print_stack(t_stack *tmp, int flag, int color)
{
	if (flag)
		write(1, "a: ", 3);
	else
		write(1, "b: ", 3);
	while (tmp)
	{
		if (color)
		{
			tmp->color_flag ? ft_putnbr_fd_color(tmp->content, 1) : \
			ft_putnbr_fd(tmp->content, 1);
		}
		else
			ft_putnbr_fd(tmp->content, 1);
		write(1, " ", 1);
		tmp->color_flag = 0;
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}

void	print_stack_all(t_stack *a, t_stack *b, int flag)
{
	print_stack(a, 1, flag);
	print_stack(b, 0, flag);
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_list	*inst;
	t_bonus	bonus;
	char	**tmp;

	if (argc != 1)
	{
		a = NULL;
		b = NULL;
		inst = NULL;
		while (*(++argv))
		{
			if (!(tmp = ft_split(*argv, ' ')))
				return (error_message(&a, tmp));
			if (args_error_check_bonus(tmp, &a, &bonus) == 0)
				return (error_message(&a, tmp));
			ft_clear(tmp);
		}
		if (instructions(&a, &b, inst, bonus))
			result_output(&a, &b, &inst);
	}
	return (0);
}
