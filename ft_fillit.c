/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:05:09 by amartino          #+#    #+#             */
/*   Updated: 2019/02/15 17:06:27 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_fillit(int fd)
{
	char		*file;
	t_list		*allp;

	file = ft_checks(fd);
	allp = ft_get_pieces(file);
	// printf("\033[34;01m[%s]\033[00m\n", allp->content);
	ft_lstiter(allp, ft_print_lst);
}
