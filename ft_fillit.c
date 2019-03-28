/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:05:09 by amartino          #+#    #+#             */
/*   Updated: 2019/03/28 22:21:07 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_fillit(int fd)
{
	char		*file;
	t_map		*map;

	map = NULL;
	file = ft_checks(fd);
	if (!(map = ft_memalloc(sizeof(t_map))))
		return ;
	map = ft_get_pieces(file, map);
	ft_strdel(&file);
	ft_lstiter(map->lst, ft_get_coordinate);
	ft_lstiter(map->lst, ft_print_tfeel);
	map = ft_solve(map);
/*
** 	ft_strdel(&map);
*/
}


// printf("\033[34;01m[%s]\033[00m\n", allp->content);
