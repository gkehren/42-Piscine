/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:42:10 by gkehren           #+#    #+#             */
/*   Updated: 2022/02/22 21:40:20 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	**set_square(char **tab, t_max_pos max_pos, t_pos pos)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < pos.y)
	{
		while (i < pos.x)
			i++;
		j++;
	}
	while (j < max_pos.c)
	{
		i = 0;
		while (i < max_pos.c)
		{	
			tab[j][i] = 'X';
			i++;
		}
		j++;
	}
	return (tab);
}

void	display(char **tab, t_legal legal)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < legal.j_max)
	{
		i = 0;
		while (i < legal.i_max)
		{
			write(1, &tab[j][i], 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}

/*
int main(int argc, char **argv)
{
	struct s_legal legal;
	legal.e = '.';
	legal.o = 'o';
	legal.f = 'X';
	legal.i_max = 4;
	legal.j_max = 5;
	legal.t = 10;
	legal.obc = 10;

	struct s_pos pos;
	pos.x = 0;
	pos.y = 0;

	struct s_pos pos2;
	pos.x = 0;
	pos.y = 0;

	struct s_max_pos max_pos;
	max_pos.pos = pos2;
	max_pos.c = 2;

	argv = set_square(argv, max_pos, pos);
	display(argv, legal);
}*/
