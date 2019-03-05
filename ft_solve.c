#include "fillit.h"

int		ft_initialise(t_feel *allp, char **map, int square_size, int status)
{
	float	tmp;
	int		i;
	int		j;

	if (status == 0)
	{
		tmp = ft_find_square(ft_tfeel_count(allp) * 4) + 0.999999;
		square_size = (int)tmp;
		i = square_size + 1;
		square_size = (square_size + 4) * (square_size + 4) + (square_size + 4);
		if (!(*map = (char*)malloc(sizeof(char*) * (square_size + 1))))
			return 0;
		//ft_memset(*map, 1, square_size); hein ?
		(*map)[square_size] = '\0';
		square_size = (int)tmp;
	}
	i = square_size + 1;
	j = -1;
	while (--i > 0)
	{
		while (++j < square_size)
			(*map)[j] = '.';
		(*map)[square_size] = '\n';
		printf("\n\033[34;01m[%d]\033[00m\n", square_size);
		square_size += (int)tmp + 1;
	}
	return (status ==  0 ? square_size = (int)tmp : square_size);
}

char	*ft_solve(t_feel *allp, char *map)
{
	int		square_size;

	square_size = 0;
	if ((square_size = ft_initialise(allp, &map, square_size, 0)) == 0)
		return NULL;
	map[2] = '@';
	map[7] = '@';
	map[12] = '@';
	map[17] = '@';
	map[23] = '@';
	map[28] = '@';
	ft_putstr(map);
	return (map);
}
