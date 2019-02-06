/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:19:47 by amartino          #+#    #+#             */
/*   Updated: 2019/02/06 20:01:31 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list		*current_lst;

	current_lst = lst;
	while (current_lst != NULL)
	{
		f(current_lst);
		current_lst = current_lst->next;
	}
}
