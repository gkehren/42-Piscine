/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:30:23 by lgiband           #+#    #+#             */
/*   Updated: 2022/02/20 20:01:09 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_count_letter_str(char *str, int *position)
{
	int	count;

	count = 0;
	if (str[*position])
	{
		while ((str[*position + count] == ' ' || str[*position + count] == ':')
			&& str[*position + count])
			(*position) += 1;
		while (str[*position + count] != '\n' && str[*position + count])
			count ++;
	}
	return (count);
}

int	ft_count_letter_value(char *str, int *position)
{
	int	count;

	count = 0;
	if (str[*position])
	{
		while (str[*position] == '\n' && str[*position])
			(*position) += 1;
		while ((str[*position + count] != ' ' && str[*position + count] != ':')
			&& str[*position + count])
			count ++;
	}
	return (count);
}

char	*ft_put_word(char *str, int *position, int val_or_str)
{
	char	*word;
	int		nb_letter;
	int		i;

	i = 0;
	if (val_or_str == 0)
		nb_letter = ft_count_letter_value(str, position);
	else
		nb_letter = ft_count_letter_str(str, position);
	word = malloc(sizeof(char) * (nb_letter + 1));
	while (i < nb_letter)
	{
		word[i] = str[*position];
		i ++;
		(*position) += 1;
	}
	word[nb_letter] = 0;
	return (word);
}

int	ft_count_word(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str == 0)
		return (0);
	while (str[i])
	{
		count ++;
		while (str[i] != ' ' && str[i] != ':')
			i ++;
		while (str[i] == ' ' && str[i] == ':')
			i ++;
		count ++;
		while (str[i] >= ' ' && str[i] != 127)
			i ++;
		while (str[i] == '\n')
			i ++;
	}
	return (count);
}

char	**ft_split(char	*str)
{
	char	**result;
	int		nb_word;
	int		i;
	int		position;

	i = 0;
	position = 0;
	nb_word = ft_count_word(str);
	result = malloc(sizeof(char *) * (nb_word + 1));
	while (i < nb_word)
	{
		result[i] = ft_put_word(str, &position, 0);
		i ++;
		result[i] = ft_put_word(str, &position, 1);
		i ++;
	}
	result[nb_word] = 0;
	return (result);
}
