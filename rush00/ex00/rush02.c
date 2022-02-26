/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:48:36 by gkehren           #+#    #+#             */
/*   Updated: 2022/02/05 15:43:28 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_line_first(int col)
{
	int	i;

	i = 0;
	while (i <= col)
	{
		if (i == 0)
			ft_putchar('A');
		else if (i > 0 && i < col - 1)
			ft_putchar('B');
		else if (i == col && col > 1)
			ft_putchar('A');
		i++;
	}
	ft_putchar('\n');
}

void	ft_line_last(int col)
{
	int	i;

	i = 0;
	while (i <= col)
	{
		if (i == 0)
			ft_putchar('C');
		else if (i > 0 && i < col - 1)
			ft_putchar('B');
		else if (i == col && col > 1)
			ft_putchar('C');
		i++;
	}
	ft_putchar('\n');
}

void	ft_line_other(int ligne)
{
	int	i;

	i = 0;
	while (i <= ligne)
	{
		if (i == 0)
			ft_putchar('B');
		else if (i > 0 && i < ligne - 1)
			ft_putchar(' ');
		else if (i == ligne && ligne > 1)
			ft_putchar('B');
		i++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	i = 1;
	if (x > 0 && y > 0)
	{
		ft_line_first(x);
		while (i < y - 1)
		{
			ft_line_other(x);
			i++;
		}
		if (y > 1)
			ft_line_last(x);
	}
}
