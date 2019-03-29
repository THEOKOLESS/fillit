/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:05:09 by amartino          #+#    #+#             */
/*   Updated: 2019/03/29 19:01:35 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_fillit(int fd)
{
	char		*file;
	t_map		*map;
	int			i;

	map = NULL;
	i = -1;
	file = ft_checks(fd);
	if (!(map = ft_memalloc(sizeof(t_map))))
		return ;
	map = ft_get_pieces(file, map);
	ft_strdel(&file);
	ft_lstiter(map->lst, ft_get_coordinate);
	ft_lstiter(map->lst, ft_print_tfeel);
	map = ft_solve(map);
	while (++i < 4)
		ft_strdel(&(ft_find_elem(map->lst, i)->content));
	ft_lstdel(&map->lst, ft_memset0);
	free(map);
	map = NULL;
}
/*
** printf("\033[34;01m[%s]\033[00m\n", allp->content);
*/
