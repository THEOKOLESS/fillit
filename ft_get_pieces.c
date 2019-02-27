/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pieces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:55:58 by amartino          #+#    #+#             */
/*   Updated: 2019/02/23 10:29:39 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_feel	*ft_clean_column(t_feel *begin)
{
	int		i;
	int		j;
	int		resultat;
	t_feel	*tmp;

	tmp = begin;
	while (tmp)
	{
		i = -1;
		while (++i < 4)
		{
			//printf("\033[32;01mOK\033[00m\n");  //vert
			j = i;
			resultat = 1;
			while (j < (int)(ft_strlen(tmp->content)))
			{
				if (tmp->content[j] == '#')
					resultat = 0;
				j += 5;
			}
			if (resultat == 1)
				while ((j -= 5) >= 0)
					tmp->content[j] = 'x';
		}
		tmp = tmp->next;
	}
	return (begin);
}

t_feel	*ft_clean_x(t_feel	*begin)
{
	t_feel	*tmp;
	int		size;
	int		i;
	char	*dayson;

	tmp = begin;

	while (tmp)
	{
		i = -1;
		size = 0;
		while (tmp->content[++i])
		{
			if (tmp->content[i] != 'x')
				size++;
		}
		if(!(dayson = (char*)malloc(sizeof(char) * (size + 1))))
			return NULL;
		i = -1;
		size = 0;
		while (tmp->content[++i])
		{
			if (tmp->content[i] != 'x')
			{
				dayson[size] = tmp->content[i];
				size++;
			}
		}
		dayson[size] = '\0';
		ft_strdel(&(tmp->content));
		tmp->content = dayson;
		tmp->content_size = ft_strlen(dayson);
		tmp = tmp->next;
	}
	return (begin);
}


t_feel	*ft_get_pieces(char *file)
{
	int		i;
	int		j;
	int		nb_hashtag;
	t_feel	*new;
	t_feel	*begin;

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
			if (i == 0)
				i = -1;
			begin = ft_tfeelnew((file + i + 1), j - i);
			begin->content[j - i] = '\0';
			new = begin;
		}
		else
		{
			new->next = ft_tfeelnew((file + i + 1), j - i);
			new->next->content[j - i] = '\0';
			new = new->next;
		}
		i = j + 1;
	}
	begin = ft_clean_column(begin);	
	begin = ft_clean_x(begin);
	return (begin);
}
/*
printf("\033[32;01mOK\033[00m\n");  //vert
printf("\033[32;01m%s\033[00m\n", file);
*/
