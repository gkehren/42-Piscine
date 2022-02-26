/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 08:40:41 by gkehren           #+#    #+#             */
/*   Updated: 2022/02/03 17:55:51 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putint(int a, int b)
{
	ft_putchar((a / 10) + '0');
	ft_putchar((a % 10) + '0');
	ft_putchar(' ');
	ft_putchar((b / 10) + '0');
	ft_putchar((b % 10) + '0');
	if (a < 98)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int	i;
	int	x;

	i = 0;
	while (i < 99)
	{
		x = i + 1;
		while (x <= 99)
		{
			ft_putint(i, x);
			x++;
		}
		i++;
	}
}
