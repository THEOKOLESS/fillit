/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:58:22 by amartino          #+#    #+#             */
/*   Updated: 2019/03/13 19:40:31 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_feel(const t_feel *elem, t_map *map, const int status)
{

}

int		ft_recursive(t_feel *elem, t_map *map)
{
	while(elem)
	{
		if (ft_feel(elem, map, 0))
		{
				ft_feel(elem, map, 1);
				if (ft_recursive(elem->next, map))
					return (1);
				//clean_stack
		}
		else if (elem->start < ((map->square_size * map->square_size) + map->square_size))
			elem->start++;

	}
	return (1);
}

int		ft_initialise(t_feel *allp, t_map *map)
{
	float	tmp;
	int		i;
	int		j;

	tmp = ft_find_square(ft_tfeel_count(allp) * 4) + 0.999999;
	map->square_size = (int)tmp;
	i = map->square_size + 1;
	j = -1;
	while (--i > 0)
	{
		while (++j < map->square_size)
			map->map[j] = '.';
		map->map[j] = '\n';
		map->square_size += (int)tmp + 1;
	}
	return ((int)tmp);
}

t_map	*ft_solve(t_feel *allp, t_map *map)
{
	if ((map->square_size = ft_initialise(allp, map)) == 0)
		return NULL;
	while (ft_recursive(allp, map) == 0)
	{
		map->square_size++;
		if ((map->square_size = ft_initialise(allp, map)) == 0)
			return NULL;
	}
	ft_putstr(map->map);
	return (map);
}

/*
** ft_memset(*map, 1, map->square_size); hein ?
*/
