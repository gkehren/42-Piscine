/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:17:19 by gkehren           #+#    #+#             */
/*   Updated: 2022/02/15 18:53:42 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *tab)
{
	int	i;

	i = 0;
	while (tab[i] != '\0')
		i++;
	return (i);
}

char	*ft_str(int size, char **strs, char *sep)
{
	char	*tab;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	len += ft_strlen(sep) * size - 1;
	if (size <= 0)
		len = 1;
	tab = (char *)malloc(sizeof(char) * len);
	if (tab == NULL)
		return (0);
	return (tab);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;
	char	*tab;

	i = -1;
	k = 0;
	tab = ft_str(size, strs, sep);
	while (++i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			tab[k++] = strs[i][j];
			j++;
		}
		j = 0;
		while (sep[j] && i != size - 1)
		{
			tab[k++] = sep[j];
			j++;
		}
	}
	tab[k] = '\0';
	return (tab);
}
