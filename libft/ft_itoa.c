/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvitoux <tvitoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 16:13:26 by tvitoux           #+#    #+#             */
/*   Updated: 2013/12/08 07:02:00 by tvitoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*itoalloc(int n, char *ret, size_t i)
{
	int	d;

	d = n;
	while (d /= 10)
		i++;
	if (n >= 0)
		ret = ft_strnew(i + 1);
	else
		ret = ft_strnew(i + 2);
	return (ret);
}

static char	*ft_algoa(char *ret, int n, size_t i)
{
	size_t	d;

	d = 1;
	while (n / d > 9)
		d *= 10;
	while (d)
	{
		ret[i] = '0' + (n / d) % 10;
		i++;
		n = n % d;
		d = d / 10;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_itoa(int n)
{
	char	*ret;
	size_t	i;

	ret = "-2147483648\0";
	i = 0;
	ret = itoalloc(n, ret, i);
	if (n == -2147483648)
		return (ret);
	i = 0;
	if (n < 0)
	{
		ret[i] = '-';
		n *= -1;
		i++;
	}
	ret = ft_algoa(ret, n, i);
	return (ret);
}
