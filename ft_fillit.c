/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:05:09 by amartino          #+#    #+#             */
/*   Updated: 2019/03/14 14:47:45 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_fillit(int fd)
{
	char		*file;
	t_feel		*allp;
	t_map		*map;

	allp = NULL;
	map = NULL;
	file = ft_checks(fd);
	if (!(map = ft_memalloc(sizeof(t_map))))
		return ;
	allp = ft_get_pieces(file);
	ft_strdel(&file);
	ft_tfeel_iter(allp, ft_get_coordinate);
	ft_tfeel_iter(allp, ft_print_tfeel);
	map = ft_solve(allp, map);
/*
** 	ft_strdel(&map);
*/
}


// printf("\033[34;01m[%s]\033[00m\n", allp->content);
