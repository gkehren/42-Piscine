/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:02:56 by gkehren           #+#    #+#             */
/*   Updated: 2022/02/10 12:45:26 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	r;

	if (nb < 0)
		return (0);
	else if (nb < 2)
		return (1);
	i = nb - 2;
	r = nb * (nb - 1);
	while (i > 0)
	{
		r = r * i;
		i--;
	}
	return (r);
}
/*
#include <stdio.h>
int    main()
{
    printf("%d", ft_iterative_factorial(2));
}*/
