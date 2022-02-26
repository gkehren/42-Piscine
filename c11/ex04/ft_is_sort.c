/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:45:32 by gkehren           #+#    #+#             */
/*   Updated: 2022/02/21 20:42:12 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sort_asc(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_sort_des(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	if (ft_sort_asc(tab, length, f) || ft_sort_des(tab, length, f))
		return (1);
	return (0);
}
/*
int		ft_strcmp(int nb1, int nb2)
{
	if (nb1 < nb2)
		return (-1);
	else if (nb1 == nb2)
		return (0);
	else
		return (1);
}
#include <stdio.h>
int	main()
{
	int tab[] = {9,8,7,6,5,4,3,2,1};
	printf("%d", ft_is_sort(tab, 9, &ft_strcmp));
}*/
