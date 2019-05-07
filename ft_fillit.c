/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:05:09 by amartino          #+#    #+#             */
/*   Updated: 2019/05/07 18:13:54 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int 			ft_fillit(int fd)
{
	char		*file;
	t_map		*map;

	map = NULL;
	if ((file = ft_checks(fd)) == NULL)
		return (FALSE);
	if (!(map = ft_memalloc(sizeof(t_map))))
	{
		ft_strdel(&file);
		return (FALSE);
	}
	if ((map = ft_get_pieces(file, map)) == NULL)
	{
		ft_strdel(&file);
		return (FALSE);
	}
	ft_strdel(&file);
	ft_lstiter(map->lst, ft_get_coordinate);
	if ((map = ft_solve(map)) == NULL)
		return (FALSE);
	ft_putstr(map->map);
	del(&map);
	return (TRUE);
}
// ft_lstiter(map->lst, ft_print_tfeel);
