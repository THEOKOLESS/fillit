/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvitoux <tvitoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 21:29:51 by tvitoux           #+#    #+#             */
/*   Updated: 2013/12/08 07:05:03 by tvitoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*ss1;
	char	*ss2;

	ss2 = (char *)s2;
	ss1 = s1;
	if (ss1 >= ss2)
	{
		ss2 = ss2 + n - 1;
		ss1 = ss1 + n - 1;
		while (n--)
				*ss1-- = *ss2--;
	}
	else
		ft_memcpy(s1, s2, n);
	return (s1);
}

