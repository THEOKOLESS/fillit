/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:05:09 by amartino          #+#    #+#             */
/*   Updated: 2019/04/11 22:43:43 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_fillit(int fd) //verif retour
{
	char		*file;
	t_map		*map;
	int			i;

	map = NULL;
	i = -1;
	file = ft_checks(fd); //verif retour 
	if (!(map = ft_memalloc(sizeof(t_map)))) //verif retour
		return ;
	map = ft_get_pieces(file, map); //verif retour
	ft_strdel(&file);
	ft_lstiter(map->lst, ft_get_coordinate);
	ft_lstiter(map->lst, ft_print_tfeel);
	map = ft_solve(map); //verif retour
	while (++i < 4)
		ft_strdel(&(ft_find_elem(map->lst, i)->content));
	ft_lstdel(&map->lst, ft_memset0);
	free(map);
	map = NULL;
}
/*
** printf("\033[34;01m[%s]\033[00m\n", allp->content);
*/
