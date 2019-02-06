/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:48:28 by amartino          #+#    #+#             */
/*   Updated: 2019/02/06 20:01:01 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void mycat(int fd)
{
  char			buf;
  int			r;   /*read*/
  int			i;	/*nombre de bit */
  int			j;	/*ligne size count*/
  char			h[546];	/*how many piece*/
  int			hc; /* how many piece */
  t_list		*allp; /*all pices */

  i = 0;
  r = 1;
  j = 0;
  hc = 1;
	while(read(fd, &buf, 1))
	{
		if (buf != '.' && buf != '#' && buf != '\n')
		{
			ft_putchar('[');
			ft_putchar(buf);
			ft_putstr("] is an invalid char !");
			exit(2);
		}
		if (buf != '\n')
			j++;
		else if(j > 4) /* ligne trop longue */
		{
			ft_putstr("error:");
			exit(2);
		}
		else
			j = 0;
		if (buf == '\n')
		{
			if (h[i - 1] == '\n')
				hc++;
		}
		h[i++] = buf;
		if (i > 545)
		{
				ft_putstr("error : + de 26 tetriminos dans le fd ");
				exit(2);
		} 
		
	}
	printf("\n");
	if (i < 19)
	{
		ft_putstr("error : - de 1 tetriminos dans le fd ");
		exit(2);
	}
	if (r == -1)
	{
		ft_putstr("error read");
		exit(2);
	}

	h[i] = '\0';
	allp = ft_get_pieces(h, hc);
	ft_lstiter(allp, ft_print_lst);
}

t_list *ft_get_pieces(char *file, int hc)
{
	size_t	i;
	size_t	j;
	size_t	nb_hashtag;
	t_list	*new;
	t_list	*begin;

	i = 0;
	while (--hc >= 0)
	{
		nb_hashtag = 0;
		while (file[i] != '#')
			i++;
		j = i - 1;
		while (nb_hashtag < 4)
		{
			if (file[j] == '#')
				nb_hashtag++;
			j++;
		}
		if (!(begin->content))
		{
			begin = ft_lstnew((file + i - 1), j);
			((char*)(begin->content))[j] = '\0';
			new = begin;
		}
		else
		{
			new = ft_lstnew((file + i - 1), j);
			((char*)(new->content))[j - i + 1] = '\0';
		}
		new = new->next;
		i = j;
	}
	return (begin);
}

int	main(int argc, char const *argv[])
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (argc == 2){
		 if (fd  == -1)
		{
	  		ft_putstr("error: read");
	  		exit(2);
		}
		else{
			mycat(fd);
		}
	}
	else
	{
		ft_putstr("usage:");
		exit(2);
	}
	return 0;
}
/*
printf("\033[32;01mOK\033[00m\n");  //vert
printf("\033[32;01m%s\033[00m\n", file);
*/
