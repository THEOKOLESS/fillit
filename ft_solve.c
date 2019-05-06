/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:58:22 by amartino          #+#    #+#             */
/*   Updated: 2019/05/06 16:38:44 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

static int		ft_recursive(t_list *lst, t_map *map)
{
	t_feel	*elem;
	int		max_pos;

	max_pos = (map->square_size * map->square_size) + map->square_size - 2;
	if (lst)
		elem = lst->content;
	while (lst)
	{
		if (ft_check(elem, map, max_pos))
		{
			ft_feel(elem, map, 1);
			if (ft_recursive(lst->next, map))
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

static int		ft_initialise(t_map *map, int mode)
{
	float	tmp;
	int		i;
	int		j;

	tmp = map->square_size;
	if (mode == 0)
	{
		tmp = ft_find_square(ft_count_lst(map->lst, 0) * 4) + 0.999999;
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

t_map			*ft_solve(t_map *map)
{
	t_list	*tmp;

	tmp = map->lst;
	if ((map->square_size = ft_initialise(map, 0)) == 0)
		return (NULL);
	while (ft_recursive(map->lst, map) == 0)
	{
		map->lst = tmp;
		map->square_size++;
		if ((map->square_size = ft_initialise(map, 1)) == 0)
			return (NULL);
	}
	map->lst = tmp;
	return (map);
}
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
/*
** ft_memset(*map, 1, map->square_size); hein ?
*/
