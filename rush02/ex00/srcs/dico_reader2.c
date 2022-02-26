/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dico_reader2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:46:50 by lgiband           #+#    #+#             */
/*   Updated: 2022/02/20 11:26:15 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	is_in_dico(char *str_number, t_dico_elem *dico_ref, int count)
{
	int				i;
	unsigned int	int_number;

	i = -1;
	int_number = ft_atoi(str_number);
	while (++i < count)
	{
		if (dico_ref[i].value == int_number)
			return (1);
	}
	return (0);
}

t_dico_elem	*ft_complete_dico_new(char **split, t_dico_elem *dico_ref)
{
	int			i;
	int			split_position;
	t_dico_elem	*dico;

	i = -1;
	split_position = 0;
	dico = malloc(sizeof(t_dico_elem) * SDICO);
	while (++i < SDICO && split[split_position + 1])
	{
		if (split_position % 2 == 1)
			split_position ++;
		if (is_in_dico(split[split_position], dico_ref, SDICO) == 1)
		{
			if (is_in_dico(split[split_position], dico, i) == 0)
				dico[i] = ft_put_elem(split[split_position],
						split[split_position + 1]);
		}
		split_position ++;
	}
	while (split[++split_position])
		free(split[split_position]);
	if (i == SDICO)
		return (dico);
	return (0);
}

t_dico_elem	*ft_parse_new_dico(char *input_dico, t_dico_elem *dico_ref)
{
	t_dico_elem	*dico;
	char		*all_file;
	char		**split_all_file;
	int			nb_char;
	int			erreur;

	nb_char = 0;
	erreur = ft_count_line(input_dico, &nb_char);
	if (erreur == -1)
		return (0);
	all_file = malloc(sizeof(char) * (nb_char + 1));
	write_file_in_tab(input_dico, nb_char, &all_file);
	split_all_file = ft_split(all_file);
	dico = ft_complete_dico_new(split_all_file, dico_ref);
	free(all_file);
	free(split_all_file);
	if (dico == 0)
		return (0);
	return (dico);
}

void	ft_complete_dico(t_dico_elem **dico, char **split)
{
	int	i;

	i = 0;
	while (i < SDICO)
	{
		(*dico)[i] = ft_put_elem(split[i * 2], split[(i * 2) + 1]);
		i ++;
	}
	i = i * 2;
	while (split[i])
	{
		free(split[i]);
		i ++;
	}
}

t_dico_elem	*ft_parse_dico(char *input_dico)
{
	t_dico_elem	*dico;
	char		*all_file;
	char		**split_all_file;
	int			nb_char;

	nb_char = 0;
	ft_count_line(input_dico, &nb_char);
	all_file = malloc(sizeof(char) * (nb_char + 1));
	write_file_in_tab(input_dico, nb_char, &all_file);
	split_all_file = ft_split(all_file);
	dico = malloc(sizeof(t_dico_elem) * (SDICO));
	ft_complete_dico(&dico, split_all_file);
	free(all_file);
	free(split_all_file);
	return (dico);
}
