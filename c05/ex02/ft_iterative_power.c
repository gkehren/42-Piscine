/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:03:18 by gkehren           #+#    #+#             */
/*   Updated: 2022/02/10 13:44:29 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	r;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	r = 1;
	while (power > 0)
	{
		r = r * nb;
		power--;
	}
	return (r);
}
/*
#include <stdio.h>
int main()
{
	printf("%d", ft_iterative_power(5, 3));
}*/
