#include "../push_swap.h"

int	get_next_line(char **line)
{
	int		i;
	char	buf[2];

	if (!(*line = ft_strdup("")))
		return (-1);
	i = read(0, buf, 1);
	if (i == 0)
		return (i);
	buf[1] = '\0';
	while (buf[0] != '\n' && i != 0)
	{
		if (!(*line = ft_strjoin(*line, buf)))
			return (-1);
		i = read(0, buf, 1);
		buf[1] = '\0';
	}
	return (i);
}
