/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvitoux <tvitoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:47:36 by tvitoux           #+#    #+#             */
/*   Updated: 2013/11/20 17:47:39 by tvitoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int display;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	display = n % 10;
	n = n / 10;
	if (n > 0)
		ft_putnbr_fd(n, fd);
	ft_putchar_fd(display + '0', fd);
}
