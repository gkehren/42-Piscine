/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:27:39 by gkehren           #+#    #+#             */
/*   Updated: 2022/02/05 21:19:58 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
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
		if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
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
	char str[] = "a0a";
	printf("%d", ft_str_is_alpha(str));
}*/
