/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:52:48 by amartino          #+#    #+#             */
/*   Updated: 2019/03/26 15:52:52 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


t_feel		*ft_tfeelnew(char *content, size_t content_size)
{
	t_feel	*new_lst;

	if (!(new_lst = (t_feel*)malloc(sizeof(t_feel))))
		return (NULL);
	if (!content)
	{
		new_lst->content = NULL;
		new_lst->content_size = 0;
	}
	else
	{
		if (!(new_lst->content = ft_memalloc(content_size)))
		{
			free(new_lst);
			return (NULL);
		}
		new_lst->content = ft_memcpy(new_lst->content, content, content_size);
		new_lst->content_size = content_size;
	}
	new_lst->next = NULL;
	return (new_lst);
}

void	ft_tfeel_iter(t_feel *lst, void (*f)(t_feel *elem))
{
	t_feel		*current_lst;

	current_lst = lst;
	while (current_lst != NULL)
	{
		f(current_lst);
		current_lst = current_lst->next;
	}
}

void	ft_print_tfeel(t_feel *elem)
{
	int 	i;

	i = 0;
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

int		ft_tfeel_count(t_feel *lst)
{
	int 	i;
	t_feel	*tmp;

	if (!lst->next)
		return (1);
	tmp = lst->next;
	i = 2;
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int		ft_isalpha_n(const int c)
{
	return (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) || c == '\n' ? 1 : 0);
}
