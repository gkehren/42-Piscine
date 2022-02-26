/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:22:32 by afelten           #+#    #+#             */
/*   Updated: 2022/02/13 14:53:09 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush01.h"

t_ushort	ft_first_bits(t_uint n);

int	ft_get_len_input(char *input)
{
	int	len;

	len = 0;
	while (*input)
	{
		if (*input < '1' || *input > '9')
			break ;
		else
			len++;
		input++;
		if (!*input || *input != ' ' || (*input == ' ' && !*(input + 1)))
			break ;
		input++;
	}
	if (*input)
		return (-1);
	return (len);
}

int	ft_initialize_tab(char *input, t_uint n, t_ushort *tab)
{
	int		i;
	t_uint	j;

	i = 0;
	j = 0;
	while (input[i])
	{
		if (i % 2 == 0)
		{
			if ((t_uint) input[i] > n + '0')
				return (0);
			tab[j] = input[i] - '0';
			j++;
		}
		i++;
	}
	while (j < n * n + n * 4)
	{
		tab[j] = ft_first_bits(n);
		j++;
	}
	return (1);
}

t_ushort	*ft_parse_input(char *input, t_uint *n)
{
	t_ushort	*tab;
	int			len;

	len = ft_get_len_input(input);
	*n = len / 4;
	if (len % 4 != 0 || *n > 9)
		return (0);
	tab = malloc((*n * 4 + *n * *n) * sizeof(t_ushort));
	if (tab == NULL || !ft_initialize_tab(input, *n, tab))
		return (0);
	return (tab);
}
