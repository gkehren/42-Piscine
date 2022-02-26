/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 08:59:32 by gkehren           #+#    #+#             */
/*   Updated: 2022/02/21 09:31:24 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0') && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (*tab++)
		i++;
	return (i);
}

void	ft_sort_string_tab(char **tab)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = ft_tablen(tab);
	while (i < k - 1)
	{
		j = 0;
		while (j < k - i - 1)
		{
			if (ft_strcmp(tab[j], tab[j + 1]) > 0)
				ft_swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	int	i;
	
	for (i = 0; i < argc; i++)
		printf("%s\n", argv[i]);
	ft_sort_string_tab(argv);
	printf("after:\n");
	for (i = 0; i < argc; i++)
		printf("%s\n", argv[i]);

}*/
