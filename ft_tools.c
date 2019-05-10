/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:52:48 by amartino          #+#    #+#             */
/*   Updated: 2019/05/10 11:19:35 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_get_coordinate(t_list *lst)
{
	int		x;
	int		y;
	int		i;
	int		j;
	t_feel	*elem;

	elem = lst->content;
	x = 0;
	y = 0;
	i = -1;
	j = 0;
	while (elem->content[++i])
	{
		if (elem->content[i] == '#')
		{
			elem->coordinate[j++] = x;
			elem->coordinate[j++] = y;
		}
		x++;
		if (elem->content[i] == '\n')
		{
			y++;
			x = 0;
		}
	}
}

t_feel		*ft_find_elem(t_list *lst, int position)
{
	t_feel	*elem;
	int		i;

	i = 0;
	elem = NULL;
	if (!lst)
		return (NULL);
	while (i++ <= position && lst)
	{
		elem = lst->content;
		lst = lst->next;
	}
	return (elem);
}

void		*del(t_map **map)
{
	int		count;
	int		i;

	i = -1;
	count = 0;
	if ((*map)->lst)
	{
		count = ft_count_lst((*map)->lst, 0);
		while (++i < count)
			ft_strdel(&(ft_find_elem((*map)->lst, i)->content));
		ft_lstdel(&((*map)->lst), ft_memset0);
	}
	free(*map);
	*map = NULL;
	return (NULL);
}

void		ft_memset0(void *str, size_t len)
{
	unsigned long	i;

	i = 0;
	while (i < len)
		((unsigned char*)str)[i++] = 0;
}

void		ft_print_tfeel(t_list *lst)
{
	t_feel	*elem;
	int		i;

	i = 0;
	elem = lst->content;
	if (!elem)
		return ;
	write(1, elem->content, elem->content_size);
	write(1, "\n", 1);
	ft_putnbr(elem->piece_nb);
	ft_putchar('\n');
	while (i < 8)
	{
		ft_putchar('[');
		ft_putnbr(elem->coordinate[i++]);
		ft_putstr(" , ");
		ft_putnbr(elem->coordinate[i++]);
		ft_putchar(']');
		ft_putchar('\n');
	}
	write(1, "\n\n", 2);
}
