/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:52:40 by amartino          #+#    #+#             */
/*   Updated: 2019/03/14 19:04:33 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

/*
******************************************************************************
**																			**
**								----------									**
**								 INCLUDES									**
**								----------									**
**																			**
******************************************************************************
*/
# include "Libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h> /*open etc */
# include <stdio.h> /*printf !!!*/

/*
******************************************************************************
**																			**
**								----------									**
**								STRUCTURES									**
**								----------									**
**																			**
******************************************************************************
*/
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

/*
******************************************************************************
**																			**
**								----------									**
**								PROTOTYPES									**
**								----------									**
**																			**
******************************************************************************
*/

/*
**************
**  FILLIT	**
**************
*/
void		ft_fillit(int fd);

/*
**************
**  CHECKS	**
**************
*/
char		*ft_checks(int fd);

/*
****************
** GET_PIECES **
****************
*/
t_feel		*ft_get_pieces(char *file);
t_feel		*ft_clean_x(t_feel	*begin);
t_feel		*ft_clean_column(t_feel *begin);

/*
********************
** GET_COORDINATE **
********************
*/
void		ft_get_coordinate(t_feel *allp);

/*
**************
**  SOLVE	**
**************
*/
t_map		*ft_solve(t_feel *allp, t_map *map);
int			ft_initialise(t_feel *allp, t_map *map);
int			ft_recursive(t_feel *elem, t_map *map);
int			ft_feel(const t_feel *elem, t_map *map, const int status);

/*
**************
**  TOOLS	**
**************
*/
t_feel		*ft_tfeelnew(char *content, size_t content_size);
void		ft_tfeel_iter(t_feel *lst, void (*f)(t_feel *elem));
void		ft_print_tfeel(t_feel *elem);
int			ft_tfeel_count(t_feel *lst);


#endif
