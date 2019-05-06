/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:52:40 by amartino          #+#    #+#             */
/*   Updated: 2019/05/06 16:20:39 by amartinod        ###   ########.fr       */
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
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h> /*open etc */

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
	int			piece_nb;
}				t_feel;

typedef struct 	s_map
{
	char 		map[240];
	int			square_size;
	t_list		*lst;
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
int			ft_fillit(int fd);

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
t_map		*ft_get_pieces(char *file, t_map *map);

/*
**************
**  SOLVE	**
**************
*/
t_map		*ft_solve(t_map *map);

/*
**************
**  TOOLS	**
**************
*/
void		ft_get_coordinate(t_list *lst);
t_feel		*ft_find_elem(t_list *lst, int position);
void		ft_print_tfeel(t_list *lst);
int			ft_isalpha_n(const int c);
void		ft_memset0(void *str, size_t len);

#endif
