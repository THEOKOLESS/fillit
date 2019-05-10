/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_separate_hash.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:22:35 by amartino          #+#    #+#             */
/*   Updated: 2019/05/10 18:00:12 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_error(int i, t_map *map)
{
	del(&map);
	ft_putstr_fd("error\n", STDOUT);
	exit(i);
}

void			ft_check_separate_hash(t_map *map)
{
	t_list		*tmp;
	t_feel		*elem;
	int			i;

	tmp = map->lst;
	while (tmp != NULL)
	{
		i = -2;
		elem = tmp->content;
		while ((i += 2) < 6)
		{
			if ((elem->coordinate[i] != elem->coordinate[i + 2])
			&& (elem->coordinate[i + 1] != elem->coordinate[i + 3]))
			{
				if (i >= 4)
					if (!((elem->coordinate[i - 2] == elem->coordinate[i + 2])
					|| (elem->coordinate[i - 4] == elem->coordinate[i + 2])))
						ft_error(STDOUT, map);
				if (elem->coordinate[i + 5] != (elem->coordinate[i + 1] + 1))
					if (elem->coordinate[i - 2] != elem->coordinate[i + 2])
						ft_error(STDOUT, map);
			}
		}
		tmp = tmp->next;
	}
}
