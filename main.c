/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:48:28 by amartino          #+#    #+#             */
/*   Updated: 2019/03/29 19:08:04 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char const **argv)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (argc == 2)
	{
		if (fd == -1)
		{
			ft_putstr("error: read");
			exit(2);
		}
		else
			ft_fillit(fd);
	}
	else
	{
		ft_putstr("usage:\n");
		exit(2);
	}
	return (0);
}
/*
** printf("\033[32;01mOK\033[00m\n");  //vert
** printf("\033[32;01m%s\033[00m\n", file);
*/
