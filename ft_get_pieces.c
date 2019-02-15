/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pieces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:55:58 by amartino          #+#    #+#             */
/*   Updated: 2019/02/15 17:06:20 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list *ft_get_pieces(char *file)
{
	size_t	i;
	size_t	j;
	size_t	nb_hashtag;
	t_list	*new;
	t_list	*begin;

	i = 0;
	new = NULL;
	begin = NULL;
	while (file[i])
	{
		nb_hashtag = 0;
		while (file[i] != '#' && file[i])
			i++;
		if (file[i] == '\0')
			break ;
		j = i;
		while (file[i] != '\n' && i > 0)
			i--;
		while (nb_hashtag < 4)
		{
			if (file[j] == '#')
				nb_hashtag++;
			j++;
		}
		while (file[j] != '\n' && file[j])
			j++;
		if (!(begin))
		{
			begin = ft_lstnew((file + i + 1), j - i);
			((char*)(begin->content))[j - i] = '\0';
			new = begin;
		}
		else
		{
			new->next = ft_lstnew((file + i + 1), j - i);
			((char*)(new->next->content))[j - i] = '\0';
			new = new->next;
		}
		i = j + 1;
	}
	return (begin);
}
/*
printf("\033[32;01mOK\033[00m\n");  //vert
printf("\033[32;01m%s\033[00m\n", file);
*/
