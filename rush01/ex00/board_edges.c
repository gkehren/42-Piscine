/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_edges.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:10:46 by nmathieu          #+#    #+#             */
/*   Updated: 2022/02/13 14:51:58 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

t_ushort	ft_board_up(
					t_ushort *board,
					t_uint n,
					t_uint x,
					t_uint y)
{
	(void)y;
	(void)n;
	return (board[x]);
}

t_ushort	ft_board_left(
					t_ushort *board,
					t_uint n,
					t_uint x,
					t_uint y)
{
	(void)x;
	return (board[2 * n + y]);
}

t_ushort	ft_board_down(
					t_ushort *board,
					t_uint n,
					t_uint x,
					t_uint y)
{
	(void)y;
	return (board[n + x]);
}

t_ushort	ft_board_right(
					t_ushort *board,
					t_uint n,
					t_uint x,
					t_uint y)
{
	(void)x;
	return (board[3 * n + y]);
}
