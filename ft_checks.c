/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:34:29 by amartino          #+#    #+#             */
/*   Updated: 2019/04/11 22:55:21 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_error(int i)
{
	ft_putstr_fd("error\n", 2);
	exit(i);
}

static int		ft_check_line(int j, char buf)
{
	if (buf != '\n')
		j++;
	else if (j > 4 || (j && j < 4))
		ft_error(2);
	else
		j = 0;
	return (j);
}

static int		ft_check_file_h(char *file, int i, int ch)
{
	ch++;
	if (file[i + 1] != '#' && file[i - 1] != '#' &&\
		file[i - 5] != '#' && file[i + 5] != '#')
		ft_error(2);
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
		ft_error(2);
	while (file[++i])
	{
		if (file[i] == '#')
			ch = ft_check_file_h(file, i, ch);
		if (file[i] == '\n' && (n++ + 1))
			if ((file[i + 1] == '\n' && file[i + 2] != '\n'))
			{
				if (ch != 4 || n != 4)
					ft_error(2);
				ch = 0;
				n = 0;
				i++;
			}
	}
	if (ch != 4 || n != 4)
		ft_error(2);
}

char			*ft_checks(int fd)
{
	char		buf;
	int			i;
	int			j;
	char		*file;

	i = 0;
	j = 0;
	if (!(file = (char*)malloc(sizeof(char) * 546)))
		return (NULL);
	while ((read(fd, &buf, 1)))
	{
		if (buf != '.' && buf != '#' && buf != '\n')
			ft_error(2);
		j = ft_check_line(j, buf);
		file[i++] = buf;
	}
	if (i > 546)
		ft_error(2);
	close(fd);
	file[i] = '\0';
	ft_check_file(file);
	return (file);
}
