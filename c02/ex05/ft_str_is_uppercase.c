/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 09:42:31 by gkehren           #+#    #+#             */
/*   Updated: 2022/02/05 09:44:12 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;
	int	t;
	int	f;

	i = 0;
	t = 0;
	f = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
			t = 1;
		else
			f = 1;
		i++;
	}
	if (t == 1 && f == 0)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
int main()
{
	char str[] = "ASDSDFSDLaKFDSH";
	printf("%d", ft_str_is_uppercase(str));
}*/
