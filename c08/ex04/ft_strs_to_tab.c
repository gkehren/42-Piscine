/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:09:03 by gkehren           #+#    #+#             */
/*   Updated: 2022/02/17 09:08:06 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*s_tab;

	i = 0;
	s_tab = malloc(sizeof(*s_tab) * (ac + 1));
	if (s_tab == NULL)
		return (0);
	while (i < ac)
	{
		s_tab[i].size = ft_strlen(av[i]);
		s_tab[i].str = av[i];
		s_tab[i].copy = malloc(sizeof(char) * ft_strlen(av[i]) + 1);
		if (s_tab[i].copy == NULL)
			return (0);
		ft_strcpy(s_tab[i].copy, av[i]);
		i++;
	}
	s_tab[i].size = 0;
	s_tab[i].str = 0;
	s_tab[i].copy = 0;
	return (s_tab);
}
