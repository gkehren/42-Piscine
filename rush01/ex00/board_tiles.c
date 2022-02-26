/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_tiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:23:21 by nmathieu          #+#    #+#             */
/*   Updated: 2022/02/13 14:52:19 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

t_ushort	*ft_board_tile(t_ushort *board, t_uint n, t_uint x, t_uint y)
{
	return (board + 4 * n + y * n + x);
}

// Returns the value of the tile at the provided position. If multiple values
// are possible, 255 is returned. If no value is possible, 0 is returned.
t_uchar	ft_tile_value(t_ushort tile)
{
	t_uchar	first;

	if (ft_bit_is_one(tile, 15))
	{
		first = 0;
		while (tile >> first)
		{
			if ((tile >> first) & 1)
				return (first + 1);
			first++;
		}
		return (0);
	}
	if (ft_count_ones(tile))
		return (255);
	else
		return (0);
}
