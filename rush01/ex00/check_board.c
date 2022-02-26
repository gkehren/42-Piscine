/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 19:34:09 by gkehren           #+#    #+#             */
/*   Updated: 2022/02/13 15:04:25 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	ft_check_colup(t_ushort *board, t_uint n, t_uint x)
{
	t_uint		i;
	t_uchar		max;
	t_uchar		tile;
	t_uint		count;

	count = 0;
	max = 0;
	i = 0;
	while (i < n)
	{
		tile = ft_tile_value(*ft_board_tile(board, n, x, i));
		if (tile > max)
		{
			max = tile;
			count++;
		}
		i++;
	}
	return (count == board[x]);
}

int	ft_check_coldown(t_ushort *board, t_uint n, t_uint x)
{
	t_uint		i;
	t_uchar		max;
	t_uchar		tile;
	t_uint		count;

	count = 0;
	max = 0;
	i = 0;
	while (i < n)
	{
		tile = ft_tile_value(*ft_board_tile(board, n, x, n - i - 1));
		if (tile > max)
		{
			max = tile;
			count++;
		}
		i++;
	}
	return (count == board[n + x]);
}

int	ft_check_rowleft(t_ushort *board, t_uint n, t_uint y)
{
	t_uint	count;
	t_uchar	max;
	t_uchar	value;
	t_uint	i;

	count = 0;
	max = 0;
	i = 0;
	while (i < n)
	{
		value = ft_tile_value(*ft_board_tile(board, n, i, y));
		if (value > max)
		{
			max = value;
			count++;
		}
		i++;
	}
	return (count == board[2 * n + y]);
}

int	ft_check_rowright(t_ushort *board, t_uint n, t_uint y)
{
	t_uint	count;
	t_uchar	max;
	t_uchar	value;
	t_uint	i;

	count = 0;
	max = 0;
	i = 0;
	while (i < n)
	{
		value = ft_tile_value(*ft_board_tile(board, n, n - i - 1, y));
		if (value > max)
		{
			max = value;
			count++;
		}
		i++;
	}
	return (count == board[3 * n + y]);
}

int	ft_check_board(t_ushort *board, t_uint n)
{
	t_uint	i;

	i = 0;
	while (i < n)
	{
		if (!ft_check_colup(board, n, i))
			return (0);
		if (!ft_check_coldown(board, n, i))
			return (0);
		if (!ft_check_rowleft(board, n, i))
			return (0);
		if (!ft_check_rowright(board, n, i))
			return (0);
		i++;
	}
	return (1);
}
