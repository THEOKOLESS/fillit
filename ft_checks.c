/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:34:29 by amartino          #+#    #+#             */
/*   Updated: 2019/02/15 16:18:18 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_checks(int fd)
{
	char		buf;
	int			r;   /*read*/
	int			i;	/*nombre de bit */
	int			j;	/*ligne size count*/
	char		*file;	/*how many piece*/
	int			hc; /* how many piece */

	i = 0;
	r = 1;
	j = 0;
	hc = 1;
	if (!(file = (char*)malloc(sizeof(char) * 546)))
		return NULL;
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
			if (file[i - 1] == '\n')
				hc++;
		}
		file[i++] = buf;
		if (i > 545)
		{
				ft_putstr("error : + de 26 tetriminos dans le fd ");
				exit(2);
		} 
		
	}
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

	file[i] = '\0';
	return (file);
}
