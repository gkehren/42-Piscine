/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:57:39 by gkehren           #+#    #+#             */
/*   Updated: 2022/02/05 21:18:12 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (!dest || !src)
		return (0);
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

#include <stdio.h>
int main()
{
	char tab[] = "Geraldine";
	char str[] = "Karim";
	printf("Avant :\n");
	printf("tab: %s\n", tab);
	printf("str: %s\n", str);
	ft_strlcpy(tab, str, 13);
	printf("Apres :\n");
	printf("tab: %s\n", tab);
	printf("str: %s\n", str);
	printf("%d\n", ft_strlcpy(str, tab, 3));
}
