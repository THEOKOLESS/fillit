#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h> /*open etc */
# include <stdio.h> /*printf !!!*/
typedef	struct pieces pieces;

struct pieces
{
	char piece[20];		/*une piece*/
};
pieces *ft_get_pieces(char *h, int hc);

#endif