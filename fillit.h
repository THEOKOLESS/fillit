/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:52:40 by amartino          #+#    #+#             */
/*   Updated: 2019/02/12 11:23:56 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "Libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h> /*open etc */
# include <stdio.h> /*printf !!!*/

void	ft_fillit(int fd);
void	ft_checks(int fd);
t_list	*ft_get_pieces(char *h, int hc);

#endif
