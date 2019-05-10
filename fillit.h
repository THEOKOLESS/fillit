/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:52:40 by amartino          #+#    #+#             */
/*   Updated: 2019/05/10 17:53:01 by amartino         ###   ########.fr       */
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
# include <fcntl.h>

/*
******************************************************************************
**																			**
**								----------									**
**								  DEFINE									**
**								----------									**
**																			**
******************************************************************************
*/
# define FALSE 0
# define TRUE 1

# define SUCCESS 0
# define FAILURE -1

# define FIRST_INIT 0
# define ELSE 1

# define RESET 0
# define FILL 1

# define COORDINATE 8
# define NB_OF_CHAR_PER_PIECE 21
# define NB_OF_COLUMNS 4
# define NB_OF_LINES 4
# define NB_OF_HASH 4
# define SPACE_MAX 546
# define STDOUT 1

/*
******************************************************************************
**																			**
**								----------									**
**								STRUCTURES									**
**								----------									**
**																			**
******************************************************************************
*/
typedef struct	s_feel
{
	size_t		content_size;
	char		*content;
	int			coordinate[8];
	int			start;
	int			piece_nb;
}				t_feel;

typedef struct	s_map
{
	char		map[240];
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
int				ft_fillit(int fd);

/*
**************
**  CHECKS	**
**************
*/
char			*ft_checks(int fd);
void			ft_check_separate_hash(t_map *map);

/*
****************
** GET_PIECES **
****************
*/
t_map			*ft_get_pieces(char *file, t_map *map);

/*
**************
**  SOLVE	**
**************
*/
t_map			*ft_solve(t_map *map);

/*
**************
**  TOOLS	**
**************
*/
void			ft_get_coordinate(t_list *lst);
t_feel			*ft_find_elem(t_list *lst, int position);
void			*del(t_map **map);
void			ft_memset0(void *str, size_t len);
void			ft_print_tfeel(t_list *lst);

#endif
