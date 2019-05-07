/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:34:29 by amartino          #+#    #+#             */
/*   Updated: 2019/05/07 17:21:45 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_error(int i, char **file)
{
	ft_strdel(file);
	ft_putstr_fd("error\n", 1);
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

static int		ft_check_file_h(char *file, int i, int ch)
{
	int		nb_pt;

	ch++;
	nb_pt = 0;
	if ((file[i + 1] == '.' && file[i + 2] == '#')
		|| (file[i + 1] == '.' && file[i + 2] == '.' && file[i + 3] == '#'))
		ft_error(STDOUT, &file);
	i++;
	while (ch < 4 && file[i] && file[i] != '#')
	{
		nb_pt++;
		i++;
	}
	if (nb_pt > 4)
		ft_error(1, &file);
	return (ch);
}

static void		ft_check_file(char *file)
{
	int	i;
	int	ch;
	int	n;

	n = 0;
	i = -1;
	ch = 0;
	if (file[0] == '\n')
		ft_error(STDOUT, &file);
	while (file[++i])
	{
		if (file[i] == '#')
			ch = ft_check_file_h(file, i, ch);
		if (file[i] == '\n' && (n++ + 1))
			if ((file[i + 1] == '\n' && file[i + 2] != '\n'))
			{
				if (ch != 4 || n != 4)
					ft_error(STDOUT, &file);
				ch = 0;
				n = 0;
				i++;
			}
	}
	if (ch != 4 || n != 4)
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
	ret = 0;
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
