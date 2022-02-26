/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:20:33 by gkehren           #+#    #+#             */
/*   Updated: 2022/02/06 17:55:48 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		is_start;

	i = 0;
	is_start = 1;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (is_start == 1)
				str[i] = str[i] - 32;
			is_start = 0;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			is_start = 0;
		else
			is_start = 1;
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
int main()
{
	char str[] = "saLut, comment tu vas ? 42mots ]quarante-deux; cinquante+et+un";
	printf("Avant: %s | ", str);
	ft_strcapitalize(str);
	printf("Apres: %s", str);
}*/
