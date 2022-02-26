/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:56:52 by gkehren           #+#    #+#             */
/*   Updated: 2022/02/13 11:13:49 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "rush01.h"

int	main(int argc, char **argv)
{
	t_uint		n;
	t_ushort	*board;

	if (argc != 2)
	{
		write(1, "Error\n", 7);
		return (1);
	}
	board = ft_parse_input(argv[1], &n);
	if (!board)
	{
		write(1, "Error\n", 7);
		return (1);
	}
	ft_resolve_init(board, n);
	if (!ft_resolve(board, n))
	{
		free(board);
		write(1, "Error\n", 7);
		return (1);
	}
	ft_print_board(board, n);
	free(board);
	return (0);
}
