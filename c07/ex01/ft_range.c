/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:04:49 by gkehren           #+#    #+#             */
/*   Updated: 2022/02/23 17:11:36 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*tab;

	if (min >= max)
		return (0);
	tab = (int *) malloc(sizeof(int) * (max - min));
	if (tab == NULL)
		return (0);
	i = 0;
	while (min < max)
	{
		tab[i] = min;
		min++;
		i++;
	}
	return (tab);
}
/*
#include <stdio.h>
int 	main()
{
	int i;
	int *tab;
	tab = ft_range(-7, 9);
	for (i = 0; i < 16; i++)
		printf("%d\n", tab[i]);
}*/
