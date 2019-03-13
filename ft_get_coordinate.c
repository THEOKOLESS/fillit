#include "fillit.h"

void	ft_get_coordinate(t_feel *elem)
{
	int		x;
	int		y;
	int		i;
	int		j;

	x = 0;
	y = 0;
	i = -1;
	j = 0;
	while (elem->content[++i])
	{
		if (elem->content[i] == '#')
		{
			elem->coordinate[j++] = x;
			elem->coordinate[j++] = y;
		}
		x++;
		if (elem->content[i] == '\n')
		{
			y++;
			x = 0;
		}
	}
}
