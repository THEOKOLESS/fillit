/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:58:22 by amartino          #+#    #+#             */
/*   Updated: 2019/05/08 16:17:11 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		ft_check_if_empty(const t_feel *elem, t_map *map, int max_pos)
{
	int			pos;
	int			i;

	i = 0;
	while (i < COORDINATE)
	{
		pos = elem->start + elem->coordinate[i] + \
		(elem->coordinate[i + 1] * (map->square_size + 1));
		if (pos > max_pos || ft_isalpha((int)map->map[pos])
			|| (map->map[pos] == '\n'))
			return (FALSE);
		i += 2;
	}
	return (TRUE);
}

static void		ft_feel(const t_feel *elem, t_map *map, const int mode)
{
	int			i;
	int			position;
	char		ascii;

	i = 0;
	if (mode == FILL)
		ascii = 'A' + elem->piece_nb;
	else if (mode == RESET)
		ascii = '.';
	while (i < COORDINATE)
	{
		position = elem->start + elem->coordinate[i] + \
		(elem->coordinate[i + 1] * (map->square_size + 1));
		map->map[position] = ascii;
		i += 2;
	}
	return ;
}

static int		ft_recursive(t_list *lst, t_map *map)
{
	t_feel		*elem;
	int			max_position;

	max_position = (map->square_size * map->square_size) + map->square_size - 2;
	if (lst)
		elem = lst->content;
	while (lst)
	{
		if (ft_check_if_empty(elem, map, max_position))
		{
			ft_feel(elem, map, FILL);
			if (ft_recursive(lst->next, map) == SUCCESS)
				return (SUCCESS);
			ft_feel(elem, map, RESET);
			elem->start++;
		}
		else if (elem->start + 1 < max_position)
			elem->start++;
		else
		{
			elem->start = RESET;
			return (FAILURE);
		}
	}
	return (SUCCESS);
}

static int		ft_initialise(t_map *map, int mode)
{
	float		size_of_square;
	int			i;
	int			j;

	size_of_square = map->square_size;
	if (mode == FIRST_INIT)
	{
		size_of_square = ft_find_square(ft_count_lst(map->lst, 0) * NB_OF_HASH)
			+ 0.999999;
		map->square_size = (int)size_of_square;
	}
	i = map->square_size;
	j = 0;
	while (i > 0)
	{
		while (j < map->square_size)
		{
			map->map[j] = '.';
			j++;
		}
		map->map[j++] = '\n';
		map->square_size += (int)size_of_square + 1;
		i--;
	}
	return ((int)size_of_square);
}

t_map			*ft_solve(t_map *map)
{
	t_list		*size_of_square;

	size_of_square = map->lst;
	if ((map->square_size = ft_initialise(map, FIRST_INIT)) == FALSE)
		return (NULL);
	while (ft_recursive(map->lst, map) == FAILURE)
	{
		map->lst = size_of_square;
		map->square_size++;
		if ((map->square_size = ft_initialise(map, ELSE)) == FALSE)
			return (NULL);
	}
	map->lst = size_of_square;
	return (map);
}
