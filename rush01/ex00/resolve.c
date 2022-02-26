/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:22:10 by nmathieu          #+#    #+#             */
/*   Updated: 2022/02/13 15:04:44 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush01.h"

int	ft_contains_impossible(t_ushort *board, t_uint n)
{
	t_uint	i;

	i = 4 * n;
	while (i < 4 * n + n * n)
	{
		if (board[i] == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_resolve(t_ushort *board, t_uint n)
{
	int		has_changed;
	t_uint	x;
	t_uint	y;

	while (1)
	{
		has_changed = 0;
		if (ft_place_singles(board, n))
			has_changed = 1;
		if (!has_changed)
			break ;
	}
	if (ft_contains_impossible(board, n))
		return (0);
	if (ft_backtrack_pos(board, n, &x, &y))
		return (ft_backtrack(board, n, x, y));
	else
		return (ft_check_board(board, n));
}
