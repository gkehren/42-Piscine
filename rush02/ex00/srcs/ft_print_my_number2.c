/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_my_number2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 22:08:33 by lgiband           #+#    #+#             */
/*   Updated: 2022/02/20 10:06:31 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_check_number(char *str, int *minus)
{
	int	i;

	i = 0;
	if (str[i] == '-')
	{
		*minus = 1;
		i ++;
	}
	if (str[i] == 0)
		return (0);
	while (str[i])
	{
		if (str[i] > '9' || str[i] < 0)
			return (0);
		i ++;
	}
	return (1);
}

int	ft_intlen(unsigned int number)
{
	int	count;

	count = 0;
	if (number == 0)
		return (1);
	while (number > 0)
	{
		count ++;
		number /= 10;
	}
	return (count);
}

int	ft_is_in_dico(unsigned int number, t_dico_elem *dico)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (number == dico[i].value)
			return (1);
		i ++;
	}
	return (0);
}

unsigned int	ft_power(unsigned int nb, unsigned int power)
{
	if (power > 0)
		return (nb * ft_power(nb, power - 1));
	else
		return (1);
}

void	ft_putdico(unsigned int number, t_dico_elem *dico)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (number == dico[i].value)
			ft_putstr(dico[i].str_val);
		i ++;
	}
}
