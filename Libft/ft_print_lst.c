/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:48:18 by amartino          #+#    #+#             */
/*   Updated: 2019/02/12 10:21:25 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_lst(t_list *elem)
{
	if (!elem)
		return ;
	write(1, elem->content, elem->content_size);
	write(1, "\n\n", 2);
}
