/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pieces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:55:58 by amartino          #+#    #+#             */
/*   Updated: 2019/03/26 00:37:04 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			*ft_memchr_last(const void *s, int c, size_t n)
{
	unsigned char	*s_u;
	unsigned char	*tmp;

	s_u = (unsigned char*)s;
	tmp = NULL;
	while (n > 0)
	{
		if (*s_u == (unsigned char)c)
			tmp = s_u;
		s_u++;
		n--;
	}
	return (tmp ? tmp : NULL);
}

static t_feel	*ft_clean_column(t_feel *begin)
{
	int		i;
	int		j;
	t_feel	*tmp;

	tmp = begin;
	while (tmp)
	{
		i = -1;
		while (++i < 4)
		{
			j = i;
			if (tmp->content[j] != '#' && tmp->content[j + 5] != '#'
				&& tmp->content[j + 10] != '#' && tmp->content[j + 15] != '#')
				while ((j += 5) <= 25)
					tmp->content[j - 5] = 'x';
		}
		tmp = tmp->next;
	}
	return (begin);
}

static t_feel	*ft_clean_x(t_feel *tmp)
{
	int		size;
	int		max;
	int		i;
	char	*dayson;

	i = -1;
	size = 0;
	while (tmp->content[i + 1] != '.' && tmp->content[i + 1] != '#')
		i++;
	max = (char*)ft_memchr_last(tmp->content, '#', 20) - tmp->content;
	while (i++ <= max)
		if (tmp->content[i] != 'x')
			size++;
	if (!(dayson = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = -1;
	size = 0;
	while (tmp->content[++i])
		if (tmp->content[i] != 'x')
			dayson[size++] = tmp->content[i];
	dayson[size] = '\0';
	ft_strdel(&(tmp->content));
	tmp->content = dayson;
	tmp->content_size = ft_strlen(dayson);
	return (tmp);
}

static t_feel	*ft_clean(t_feel *begin)
{
	int		i;
	int		j;
	t_feel	*tmp;

	tmp = ft_clean_column(begin);
	while (tmp)
	{
		i = -5;
		while ((i += 5) < 20)
		{
			j = i;
			if (ft_memchr(tmp->content + j, '#', 4) == NULL)
				while (j < i + 5)
					tmp->content[j++] = 'x';
		}
		tmp = ft_clean_x(tmp);
		tmp = tmp->next;
	}
	return (begin);
}

static t_feel	*ft_tfeel(t_feel *elem, char *file)
{
	if (!(elem))
	{
		if (!(elem = ft_tfeelnew((file), 20)))
			return (NULL);
		elem->content[19] = '\0';
		elem->piece_nb = 0;
	}
	else
	{
		if (!(elem->next = ft_tfeelnew((file), 20)))
			return (NULL);
		elem->next->content[19] = '\0';
		elem->next->piece_nb = elem->piece_nb + 1;
		elem = elem->next;
	}
	return (elem);
}

t_feel			*ft_get_pieces(char *file)
{
	int		i;
	int		size;
	t_feel	*begin;
	t_feel	*new;

	i = -21;
	begin = NULL;
	size = ft_strlen(file);
	while ((i += 21) < size)
	{
		if (!begin)
		{
			if (!(begin = ft_tfeel(begin, file + i)))
				return (NULL);
			new = begin;
		}
		else
		{
			if (!(new->next = ft_tfeel(new, file + i)))
				return (NULL);
			new = new->next;
		}
	}
	begin = ft_clean(begin);
	return (begin);
}

/*
** printf("\033[32;01mOK\033[00m\n");  //vert
** printf("\033[32;01m%s\033[00m\n", file);
*/
