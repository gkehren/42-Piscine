/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:39:07 by gkehren           #+#    #+#             */
/*   Updated: 2022/02/10 19:15:41 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = nb - 1;
	if (nb < 1)
		return (0);
	while (nb > 0 && i > 1)
	{
		if (nb % i == 0)
			return (0);
		i--;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	nb++;
	if (ft_is_prime(nb) == 0)
		while (ft_is_prime(nb) == 0)
			nb++;
	return (nb);
}

#include <stdio.h>
int	main()
{
	printf("%d", ft_find_next_prime(2000012592));
}
