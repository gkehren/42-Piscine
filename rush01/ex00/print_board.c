/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:02:56 by nmathieu          #+#    #+#             */
/*   Updated: 2022/02/13 14:53:22 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush01.h"

// Prints a character to stdout.
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_board(t_ushort *board, t_uint n)
{
	t_uint	x;
	t_uint	y;
	t_uchar	value;

	y = 0;
	while (y < n)
	{
		x = 0;
		while (x < n)
		{
			value = ft_tile_value(*ft_board_tile(board, n, x, y));
			if (value == 0)
				ft_putchar('?');
			else if (value == 255)
				ft_putchar('*');
			else
				ft_putchar(value + '0');
			if (x != n - 1)
				ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
