/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:20:45 by gkehren           #+#    #+#             */
/*   Updated: 2022/02/11 13:23:28 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int	**range, int min, int max)
{
	int	i;
	int	*tab;

	if (min >= max)
	{
		tab = NULL;
		return (0);
	}
	tab = malloc(sizeof(int) * (max - min));
	if (tab == NULL)
		return (-1);
	i = 0;
	while (min < max)
	{
		tab[i] = min;
		min++;
		i++;
	}
	*range = tab;
	return (i);
}
