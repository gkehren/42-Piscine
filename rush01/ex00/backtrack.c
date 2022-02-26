/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:40:19 by nmathieu          #+#    #+#             */
/*   Updated: 2022/02/13 16:29:42 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <stdlib.h>
#include <limits.h>

int	ft_backtrack_pos(t_ushort *board, t_uint n, t_uint *x, t_uint *y)
{
	t_uint		min;
	t_uint		ones;
	t_uint		cur_x;
	t_uint		cur_y;

	min = n;
	cur_y = UINT_MAX;
	while (++cur_y < n)
	{
		cur_x = UINT_MAX;
		while (++cur_x < n)
		{
			if (ft_bit_is_one(*ft_board_tile(board, n, cur_x, cur_y), 15))
				continue ;
			ones = ft_count_ones(*ft_board_tile(board, n, cur_x, cur_y));
			if (ones > min)
				continue ;
			min = ones;
			*x = cur_x;
			*y = cur_y;
			if (ones == 2)
				return (1);
		}
	}
	return (min != n);
}

int	ft_backtrack(t_ushort *board, t_uint n, t_uint x, t_uint y)
{
	t_uint		i;
	t_ushort	*board_clone;
	t_uint		len;

	len = (n * 4 + n * n) * sizeof(t_ushort);
	board_clone = malloc(len);
	if (!board_clone)
		return (0);
	i = UINT_MAX;
	while (*ft_board_tile(board, n, x, y) >> ++i)
	{
		if (!ft_bit_is_one(*ft_board_tile(board, n, x, y), i))
			continue ;
		ft_memcpy(board, board_clone, len);
		*ft_board_tile(board_clone, n, x, y) = ft_bit(i);
		ft_place(board_clone, n, x, y);
		if (!ft_resolve(board_clone, n))
			continue ;
		ft_memcpy(board_clone, board, len);
		free(board_clone);
		return (1);
	}
	free(board_clone);
	return (0);
}
