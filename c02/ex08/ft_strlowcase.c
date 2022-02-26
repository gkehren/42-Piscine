/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:09:06 by gkehren           #+#    #+#             */
/*   Updated: 2022/02/05 16:14:14 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
int main()
{
	char str[] = "ASD0GDf";
	printf("Avant: %s | ", str);
	ft_strlowcase(str);
	printf("Apres: %s", str);
}*/
