#include "../push_swap.h"

int	arg_collection(char **argv, t_stack **a)
{
	char	**tmp;
	int		i;

	i = 1;
	while (argv[i])
	{
		if (!(tmp = ft_split(argv[i], ' ')))
			return (error_message(a, tmp));
		if (args_error_check(tmp, a) == 0)
			return (error_message(a, tmp));
		free(tmp[0]);
		free(tmp);
		i++;
	}
	return (1);
}
