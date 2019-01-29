/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvitoux <tvitoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 10:20:05 by tvitoux           #+#    #+#             */
/*   Updated: 2013/11/27 15:04:47 by tvitoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	int		*i;
	size_t	n;

	if (size)
	{
		n = 0;
		i = (int *)malloc(sizeof(int *) * size);
		if (i)
			while (n <= size)
				i[n++] = 0;
		return (i);
	}
	return (NULL);
}
