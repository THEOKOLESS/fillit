/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:52:40 by amartino          #+#    #+#             */
/*   Updated: 2019/03/13 18:31:49 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "Libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h> /*open etc */
# include <stdio.h> /*printf !!!*/

typedef struct 	s_feel
{
	size_t		content_size;
	char		*content;
	int			coordinate[8];
	int			start;
	struct s_feel	*prev;
	struct s_feel	*next;
}				t_feel;

typedef struct 	s_map
{
	char 		map[240];
	int			square_size;
}				t_map;

void		ft_fillit(int fd);
char		*ft_checks(int fd);
t_feel		*ft_get_pieces(char *file);
t_feel		*ft_tfeelnew(char *content, size_t content_size);
void		ft_tfeel_iter(t_feel *lst, void (*f)(t_feel *elem));
void		ft_print_tfeel(t_feel *elem);
void		ft_get_coordinate(t_feel *allp);
int			ft_tfeel_count(t_feel *lst);
t_map		*ft_solve(t_feel *allp, t_map *map);

#endif
