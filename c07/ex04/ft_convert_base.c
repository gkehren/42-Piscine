/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 09:48:58 by gkehren           #+#    #+#             */
/*   Updated: 2022/02/16 16:48:54 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char*base);

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_rev_int_tab(char *tab)
{
	int	i;
	int	temp;
	int	size;

	i = 0;
	size = ft_strlen(tab);
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = temp;
		i++;
	}
}

int	ft_base_test(char *base)
{
	int		i;
	int		j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	long	n;
	char	*tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(char) * 40);
	if (!ft_base_test(base))
		return (0);
	if (nbr < 0)
	{
		n = nbr;
		n = -n;
	}
	else
		n = nbr;
	while (n > 0)
	{
		tab[i] = base[n % ft_strlen(base)];
		n /= ft_strlen(base);
		i++;
	}
	if (nbr < 0)
		tab[i] = '-';
	ft_rev_int_tab(tab);
	return (tab);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	char	*ret;
	int		i;

	nb = ft_atoi_base(nbr, base_from);
	ret = (char *) malloc(sizeof(char) * 40);
	if (!ret)
		return (NULL);
	ret = ft_putnbr_base(nb, base_to);
	if (ret == 0)
		return (0);
	i = ft_strlen(ret);
	ret[i + 1] = '\0';
	return (ret);
}
/*
#include <stdio.h>

char *ft_convert_base(char *nbr, char *base_from, char *base_to);

int	main(void)
{
	printf("42:%s\n", ft_convert_base("-54", "0123456789", "0123456789"));
	printf("-2a:%s\n", ft_convert_base("-42", "0123456789", "0123456789abcdef"));
}*/
