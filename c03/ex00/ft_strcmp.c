/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:51:14 by gkehren           #+#    #+#             */
/*   Updated: 2022/02/06 12:03:29 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
/*
#include <string.h>
#include <stdio.h>
int	main()
{
	char s1[] = "Bonjour";
	char s2[] = "Bonjou";

	printf("%d\n", ft_strcmp(s1, s2));
	printf("%d", strcmp(s1, s2));
}*/
