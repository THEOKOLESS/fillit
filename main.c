#include "fillit.h"

void mycat(int fd)
{
  char			buf;
  int			r;   /*read*/
  int			i;	/*nombre de bit */
  int			j;	/*ligne size count*/
  char			h[546];	/*how many piece*/
  int			hc; /* how many piece */
  pieces     	*allp; /*all pices */ 

  i = 0;
  r = 1;
  j = 0;
  hc = 1;
	while(read(fd, &buf, 1))
	{
		if (buf != '.' && buf != '#' && buf != '\n')
		{
			ft_putchar('[');
			ft_putchar(buf);
			ft_putstr("] is an invalid char !");
			exit(2);
		}
		if (buf != '\n')
			j++;
		else if(j > 4) /* ligne trop longue */
		{
			ft_putstr("error:");
			exit(2);
		}
		else
			j = 0;
		if (buf == '\n')
		{
			if (h[i - 1] == '\n')
				hc++;
		}
		h[i++] = buf;
		if (i > 545)
		{
				ft_putstr("error : + de 26 tetriminos dans le fd ");
				exit(2);
		} 
		
	}
	printf("\n");
	if (i < 19)
	{
		ft_putstr("error : - de 1 tetriminos dans le fd ");
		exit(2);
	}
	if (r == -1)
	{
		ft_putstr("error read");
		exit(2);
	}

	h[i] = '\0';
   	allp = ft_get_pieces(h, hc);
   	 printf("%s", allp[0].piece );
}	
 
pieces *ft_get_pieces(char *file, int hc)
{
	int 	i;
	char	buf;;
	pieces  *allp;
	int		j;
	int		l;

	i = 0;
	j = 0;
	l = 0;
		printf("\033[31;01m----------------------\033[00m\n");
			// printf("\033[32;01m%s\033[00m\n", file);
	allp = 	/*(pieces*)*/malloc(sizeof(pieces*) * hc);
	if (allp == NULL)
	{
		ft_putstr("error malloc");
		exit(2);
	}
	while(i <= hc && file[l])
	{		
		allp[i].piece[j] = file[l];
	//	printf("\033[32;01m[%d]\033[00m\n", l);
		j++;
		l++;
		if (file[l] == '\n' && file[l])
		{

			if (file[l - 1] == '\n' && file[l])
			{
				i++;
				l++;
				j = 0;
			}
		}
	}
	// printf("%s\n", allp[2].piece);
	return (allp);
}

int	main(int argc, char const *argv[])
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (argc == 2){
		 if (fd  == -1)
		{
	  		ft_putstr("error: read");
	  		exit(2);
		}
		else{
			mycat(fd);
		}
	}
	else
	{
		ft_putstr("usage:");
		exit(2);
	}
	return 0;
}