/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:05:09 by amartino          #+#    #+#             */
/*   Updated: 2019/05/06 17:14:59 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		del(t_map **map)
{
	int			count;
	int			i;

	i = -1;
	count = ft_count_lst((*map)->lst, 0);//diff avec '*(map)->lst' /priorité ?
	while (++i < count)
		ft_strdel(&(ft_find_elem((*map)->lst, i)->content));
	ft_lstdel(&((*map)->lst), ft_memset0);
	free(*map);
	*map = NULL;
	return (0);
}

int 			ft_fillit(int fd)
{
	char		*file;
	t_map		*map;

	map = NULL;
	if ((file = ft_checks(fd)) == NULL)
		return (0);
	if (!(map = ft_memalloc(sizeof(t_map))))
		return (0);
	if ((map = ft_get_pieces(file, map)) == NULL)
		return (del(&map));
	ft_strdel(&file);
	ft_lstiter(map->lst, ft_get_coordinate);
	if ((map = ft_solve(map)) == NULL)
		return (del(&map));
	ft_putstr(map->map);
	del(&map);
	return (1);
}
