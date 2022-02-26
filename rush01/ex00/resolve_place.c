/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_place.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:51:16 by nmathieu          #+#    #+#             */
/*   Updated: 2022/02/13 16:05:25 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "rush01.h"

void	ft_place(t_ushort *board, t_uint n, t_uint x, t_uint y)
{
	t_uint		i;
	t_ushort	tile;

	tile = *ft_board_tile(board, n, x, y);
	i = 0;
	while (i < n)
	{
		if (i != x)
			*ft_board_tile(board, n, i, y) &= ~tile;
		if (i != y)
			*ft_board_tile(board, n, x, i) &= ~tile;
		i++;
	}
	ft_set_bit(ft_board_tile(board, n, x, y), 15, 1);
}

int	ft_place_singles(t_ushort *board, t_uint n)
{
	t_uint		x;
	t_uint		y;
	int			ret;
	t_ushort	tile;

	ret = 0;
	y = 0;
	while (y < n)
	{
		x = 0;
		while (x < n)
		{
			tile = *ft_board_tile(board, n, x, y);
			if (!ft_bit_is_one(tile, 15) && ft_count_ones(tile) == 1)
			{
				ft_place(board, n, x, y);
				ret = 1;
			}
			x++;
		}
		y++;
	}
	return (ret);
}
