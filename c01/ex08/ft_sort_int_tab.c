/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:35:45 by gkehren           #+#    #+#             */
/*   Updated: 2022/02/04 11:01:10 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	s;
	int	i;

	i = 0;
	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			s = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = s;
			i = 0;
		}
		else
			i++;
	}	
}
/*
#include <stdio.h>

int main()
{
	int i = 0;
	int tab[5];
	tab[0]=5;
	tab[1]=4;
	tab[2]=3;
	tab[3]=2;
	tab[4]=-1;
	ft_sort_int_tab(tab, 5);
	for(i=0;i<5;i++)
    {
		printf("\ntab[%d]=%d",i,tab[i]);
    }
}*/
