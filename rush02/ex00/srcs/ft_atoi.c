/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 20:37:32 by lgiband           #+#    #+#             */
/*   Updated: 2022/02/20 14:32:05 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_is_numeric(char str)
{
	if (str > 57 || str < 48)
		return (0);
	return (1);
}

long int	ft_atoi(char *str)
{
	long int	i;
	long int	result;
	int			sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] <= 32 || str[i] == 127)
		i ++;
	while (str[i] == '-' || str[i] == '+')
	{	
		if (str[i] == '-')
			sign++;
		i ++;
	}
	while (ft_is_numeric(str[i]))
	{
		result = result * 10;
		result += str[i] - 48;
		i ++;
	}
	return (result);
}
