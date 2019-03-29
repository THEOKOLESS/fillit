/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:52:48 by amartino          #+#    #+#             */
/*   Updated: 2019/03/29 19:07:50 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_get_coordinate(t_list *lst)
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

t_feel	*ft_find_elem(t_list *lst, int position)
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

void	ft_print_tfeel(t_list *lst)
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

void	ft_memset0(void *str, size_t len)
{
	unsigned long	i;

	i = 0;
	while (i < len)
		((unsigned char*)str)[i++] = 0;
}

int		ft_isalpha_n(const int c)
{
	return (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		|| c == '\n' ? 1 : 0);
}
