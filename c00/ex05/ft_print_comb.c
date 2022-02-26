/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:42:32 by gkehren           #+#    #+#             */
/*   Updated: 2022/02/03 08:39:28 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_allprint(int i, int x, int y)
{
	ft_putchar(i + '0');
	ft_putchar(x + '0');
	ft_putchar(y + '0');
	if (i < 7)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 1;
	y = 2;
	while (i <= 9)
	{
		while (x <= 9)
		{
			while (y <= 9)
			{
				ft_allprint(i, x, y);
				y++;
			}
			y = ++x + 1;
		}
		x = ++i;
	}
}
