/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:34:29 by amartino          #+#    #+#             */
/*   Updated: 2019/05/10 17:51:08 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_error(int i, char **file)
{
	ft_strdel(file);
	ft_putstr_fd("error\n", STDOUT);
	exit(i);
}

static int		ft_check_line(int j, char buf, char *file)
{
	if (buf != '\n')
		j++;
	else if (j > 4 || (j && j < 4))
		ft_error(STDOUT, &file);
	else
		j = 0;
	return (j);
}

static int		ft_check_file_h(char *file, int i, int hash_counter)
{
	int			nb_point;

	hash_counter++;
	nb_point = 0;
	if ((file[i + 1] == '.' && file[i + 2] == '#') || (file[i + 1] == '.'
	&& file[i + 2] == '.' && file[i + 3] == '#'))
		ft_error(STDOUT, &file);
	i++;
	while (hash_counter < 4 && file[i] && file[i] != '#')
	{
		nb_point++;
		i++;
	}
	if (nb_point > 4)
		ft_error(STDOUT, &file);
	return (hash_counter);
}

static void		ft_check_file(char *file)
{
	int			i;
	int			hash_counter;
	int			line_counter;

	line_counter = 0;
	i = -1;
	hash_counter = 0;
	if (file[0] == '\n')
		ft_error(STDOUT, &file);
	while (file[++i])
	{
		if (file[i] == '#')
			hash_counter = ft_check_file_h(file, i, hash_counter);
		if (file[i] == '\n' && (line_counter++ + 1))
			if ((file[i + 1] == '\n' && file[i + 2] != '\n'))
			{
				if (hash_counter != 4 || line_counter != 4)
					ft_error(STDOUT, &file);
				hash_counter = 0;
				line_counter = 0;
				i++;
			}
	}
	if (hash_counter != 4 || line_counter != 4)
		ft_error(STDOUT, &file);
}

char			*ft_checks(int fd)
{
	char		buf;
	int			i;
	int			j;
	char		*file;
	int			ret;

	i = 0;
	j = 0;
	if (!(file = (char*)malloc(sizeof(char) * SPACE_MAX)))
		return (NULL);
	while ((ret = read(fd, &buf, 1) > SUCCESS))
	{
		if (buf != '.' && buf != '#' && buf != '\n')
			ft_error(STDOUT, &file);
		j = ft_check_line(j, buf, file);
		file[i++] = buf;
	}
	if (i > SPACE_MAX || ret == FAILURE)
		ft_error(STDOUT, &file);
	close(fd);
	file[i] = '\0';
	ft_check_file(file);
	return (file);
}
