/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:06:52 by amartino          #+#    #+#             */
/*   Updated: 2019/03/28 21:08:41 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_count_lst(t_list *lst, size_t i)
{
	t_list	*tmp;

	if (!lst->next)
		return (1);
	tmp = lst->next;
	if (i == 0)
		i = 2;
	else
		i++;
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
