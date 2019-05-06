/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pieces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:55:58 by amartino          #+#    #+#             */
/*   Updated: 2019/05/06 15:16:35 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_clean_column(t_feel *feel)
{
	int		i;
	int		j;

	i = -1;
	feel->start = 0;
	while (++i < 4)
	{
		j = i;
		if (feel->content[j] != '#' && feel->content[j + 5] != '#'
			&& feel->content[j + 10] != '#' && feel->content[j + 15] != '#')
			while ((j += 5) < 24)
				feel->content[j - 5] = 'x';
	}
	return ;
}

static t_feel	*ft_clean_x(t_feel *feel)
{
	int		size;
	int		max;
	int		i;
	char	*dayson;

	i = 0;
	size = 0;
	while (feel->content[i] != '.' && feel->content[i] != '#')
		i++;
	max = (char*)ft_memchr_last(feel->content, '#', 20) - feel->content;
	while (i <= max)
		if (feel->content[i++] != 'x')
			size++;
	if (!(dayson = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = -1;
	size = 0;
	while (++i <= max)
		if (feel->content[i] != 'x')
			dayson[size++] = feel->content[i];
	dayson[size] = '\0';
	ft_strdel(&(feel->content));
	feel->content = dayson;
	feel->content_size = ft_strlen(dayson);
	return (feel);
}

static t_map	*ft_clean(t_map *map)
{
	int		i;
	int		j;
	t_list	*tmp;
	t_feel	*feel;

	tmp = map->lst;
	while (map->lst)
	{
		feel = map->lst->content;
		ft_clean_column(feel);
		i = -5;
		while ((i += 5) < 20)
		{
			j = i;
			if (ft_memchr(feel->content + j, '#', 4) == NULL)
				while (j < i + 5 && feel->content[j])
					feel->content[j++] = 'x';
		}
		feel->content[19] = '\0';
		feel = ft_clean_x(feel);
		map->lst->content = feel;
		map->lst = map->lst->next;
	}
	map->lst = tmp;
	return (map);
}

static t_list	*ft_tfeel(t_list *elem, char *file)
{
	t_feel	*feel;

	feel = NULL;
	if (!(elem))
	{
		if (!(elem = ft_lstnew((void*)&feel, sizeof(t_feel))))
			return (NULL);
		feel = elem->content;
		if (!(feel->content = ft_strsub(file, 0, 19)))
			return (NULL);
		feel->piece_nb = 0;
		elem->content = feel;
	}
	else
	{
		if (!(elem->next = ft_lstnew((void*)&feel, sizeof(t_feel))))
			return (NULL);
		feel = elem->next->content;
		if ((feel->content = ft_strsub(file, 0, 19)) == NULL)
			return (NULL);
		feel->piece_nb = ft_find_elem(elem, 0)->piece_nb + 1;
		elem->next->content = feel;
		elem = elem->next;
	}
	return (elem);
}

t_map			*ft_get_pieces(char *file, t_map *map)
{
	int		i;
	int		size;
	t_list	*tmp;

	i = -21;
	size = ft_strlen(file);
	while ((i += 21) < size)
	{
		if (!map->lst)
		{
			if (!(map->lst = ft_tfeel(map->lst, file + i)))
				return (NULL);
			tmp = map->lst;
		}
		else
		{
			if (!(map->lst->next = ft_tfeel(map->lst, file + i)))
				return (NULL);
			map->lst = map->lst->next;
		}
	}
	map->lst = tmp;
	if ((map = ft_clean(map)) == NULL)
		return (NULL);
	return (map);
}

/*
** printf("\033[32;01mOK\033[00m\n");  //vert
** printf("\033[32;01m%s\033[00m\n", file);
*/
