/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:58:22 by amartino          #+#    #+#             */
/*   Updated: 2019/03/25 18:08:57 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"



/*
** static	void 	ft_putmap(char *s)
** {
** 	int i;
**
** 	i = 0;
** 	ft_putchar(' ');
** 	while (s[i])
** 	{
** 			ft_putchar(s[i++]);
** 			ft_putchar(' ');
** 	}
** 	ft_putchar('\n');
**
** }
*/

static	int		ft_check(const t_feel *elem, t_map *map, int max_pos)
{
	int		pos;
	int		i;

	i = -2;
	while ((i += 2) < 8)
	{
		pos = elem->start + elem->coordinate[i] + \
		(elem->coordinate[i + 1] * (map->square_size + 1));
		if (pos > max_pos || ft_isalpha_n((int)map->map[pos]))
			return (0);
	}
	return (1);
}

static int		ft_feel(const t_feel *elem, t_map *map, const int mode)
{
	int		i;
	int		pos;
	char	ascii;

	i = -2;
	if (mode == 1)
		ascii = 65 + elem->piece_nb;
	else if (mode == 2)
		ascii = '.';
	while ((i += 2) < 8)
	{
		pos = elem->start + elem->coordinate[i] + \
		(elem->coordinate[i + 1] * (map->square_size + 1));
		map->map[pos] = ascii;
	}
	return (1);
}

static int		ft_recursive(t_feel *elem, t_map *map)
{
	int		max_pos;

	max_pos = (map->square_size * map->square_size) + map->square_size - 2; /*pas le meme resultat avec - 3 mais bon malgres tous */
	while (elem)
	{
		if (ft_check(elem, map, max_pos))
		{
			ft_feel(elem, map, 1);
			if (ft_recursive(elem->next, map))
				return (1);
			ft_feel(elem, map, 2);
			elem->start++;
		}
		else if (elem->start + 1 < max_pos)
			elem->start++;
		else
		{
			elem->start = 0;
			return (0);
		}
	}
	return (1);
}

static int		ft_initialise(t_feel *allp, t_map *map, int mode)
{
	float	tmp;
	int		i;
	int		j;

	tmp = map->square_size;
	if (mode == 0)
	{
		tmp = ft_find_square(ft_tfeel_count(allp) * 4) + 0.999999;
		map->square_size = (int)tmp;
	}
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
	if ((map->square_size = ft_initialise(allp, map, 0)) == 0)
		return (NULL);
	while (ft_recursive(allp, map) == 0)
	{
		map->square_size++;
		if ((map->square_size = ft_initialise(allp, map, 1)) == 0)
			return (NULL);
	}
	ft_putstr(map->map);
	return (map);
}

/*
** ft_memset(*map, 1, map->square_size); hein ?
*/
