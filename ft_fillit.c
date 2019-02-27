/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:05:09 by amartino          #+#    #+#             */
/*   Updated: 2019/02/23 14:14:48 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_fillit(int fd)
{
	char		*file;
	t_feel		*allp;

	allp = NULL;
	file = ft_checks(fd);
	allp = ft_get_pieces(file);
	// printf("\033[34;01m[%s]\033[00m\n", allp->content);
	ft_tfeel_iter(allp, ft_print_tfeel);
}
