/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:48:28 by amartino          #+#    #+#             */
/*   Updated: 2019/05/06 17:14:39 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char const **argv)
{
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("error: read");
			exit(2);
		}
		else
			if (ft_fillit(fd) == 0)
			 	ft_putstr("error\n");
		close(fd);
	}
	else
	{
		ft_putstr("usage: ./fillit ./path/file\n");
		exit(2);
	}
	return (0);
}
