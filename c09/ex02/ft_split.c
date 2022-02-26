/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 09:59:43 by gkehren           #+#    #+#             */
/*   Updated: 2022/02/15 12:26:06 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_in(char *tab, char c)
{
	int	i;

	i = 0;
	while (tab[i] != '\0')
	{
		if (tab[i] == c)
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	ft_count_word(char *str, char *charset)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_is_in(charset, str[i + 1]) == 1
			&& ft_is_in(charset, str[i]) == 0)
			count++;
		i++;
	}
	return (count);
}

void	ft_split_word(char *dest, char *src, char *charset)
{
	int	i;

	i = 0;
	while (ft_is_in(charset, src[i]) == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	ft_split_write(char **split, char *str, char *charset)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (str[i] != '\0')
	{
		if (ft_is_in(charset, str[i]) == 1)
			i++;
		else
		{
			j = 0;
			while (ft_is_in(charset, str[i + j]) == 0)
				j++;
			split[c] = (char *)malloc(sizeof(char) * (j + 1));
			ft_split_word(split[c], str + i, charset);
			i += j;
			c++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		c;

	c = ft_count_word(str, charset);
	tab = (char **)malloc(sizeof(char *) * (c + 1));
	tab[c] = 0;
	ft_split_write(tab, str, charset);
	return (tab);
}
