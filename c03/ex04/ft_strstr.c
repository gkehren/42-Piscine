/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 09:38:56 by gkehren           #+#    #+#             */
/*   Updated: 2022/02/09 13:25:54 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[i] == 0)
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (str[i + j] == to_find[j])
			{
				j++;
				if (to_find[j] == '\0')
					return (str + i);
			}
		}
		i++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
	char src[14] = "This is a test";
	char *res;

	res = ft_strstr(src, "test");
	if (res)
		printf("found, %s\n", res);
	else
		printf("not found\n");
	return (0);
}*/