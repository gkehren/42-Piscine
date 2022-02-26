/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:55:36 by nmathieu          #+#    #+#             */
/*   Updated: 2022/02/13 14:54:33 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	ft_init_tile_with(
			t_ushort *tile,
			t_ushort number,
			t_uint distance,
			t_uint n)
{
	t_uint	i;

	if (number == 1)
	{
		if (distance == 0)
			*tile &= ft_bit(n - 1);
		else
			*tile &= ft_first_bits(n - 1);
	}
	else if (number == n)
	{
		*tile &= ft_bit(distance);
	}
	else
	{
		i = n + 1 - number + distance;
		if (i > n)
			i = n;
		*tile &= ft_first_bits(i);
	}
}

void	ft_init_tile(t_ushort *board, t_uint n, t_uint x, t_uint y)
{
	ft_init_tile_with(
		ft_board_tile(board, n, x, y),
		ft_board_up(board, n, x, y),
		y,
		n);
	ft_init_tile_with(
		ft_board_tile(board, n, x, y),
		ft_board_right(board, n, x, y),
		n - x - 1,
		n);
	ft_init_tile_with(
		ft_board_tile(board, n, x, y),
		ft_board_down(board, n, x, y),
		n - y - 1,
		n);
	ft_init_tile_with(
		ft_board_tile(board, n, x, y),
		ft_board_left(board, n, x, y),
		x,
		n);
}

void	ft_resolve_init(t_ushort *board, t_uint n)
{
	t_uint	x;
	t_uint	y;

	y = 0;
	while (y < n)
	{
		x = 0;
		while (x < n)
		{
			ft_init_tile(board, n, x, y);
			x++;
		}
		y++;
	}
}
