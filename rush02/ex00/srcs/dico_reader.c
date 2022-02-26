/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dico_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 00:37:35 by lgiband           #+#    #+#             */
/*   Updated: 2022/02/20 21:11:57 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

t_dico_elem	ft_put_elem(char *value, char *word)
{
	t_dico_elem		elem;
	unsigned int	int_value;

	int_value = ft_atoi(value);
	free(value);
	elem.value = int_value;
	elem.str_val = word;
	return (elem);
}

int	give_me_a_dico(int argc, char *argv[], t_dico_elem **dico_ref,
		t_dico_elem **new_dico)
{
	*dico_ref = ft_parse_dico("numbers.dict");
	if (argc == 3)
	{
		*new_dico = ft_parse_new_dico(argv[1], *dico_ref);
		if (*new_dico == 0)
		{
			ft_putstr("Dict Error\n");
			return (0);
		}
	}
	return (1);
}

int	ft_check_input(char *input)
{
	long int	nb;
	int			i;

	i = -1;
	while (input[++i] != '\0')
	{
		if (input[i] < '0' || input[i] > '9')
			return (display_error());
	}
	nb = ft_atoi(input);
	if (nb > 4294967295)
		return (display_error());
	return (1);
}

void	second(t_dico_elem	**dico_ref, t_dico_elem	**new_dico,
		char *argv[], int argc)
{
	int	i;

	i = -1;
	if (argc == 2)
	{
		if (ft_check_input(argv[1]) == 0)
			return ;
		if (ft_check_input(argv[1]) == 2)
			ft_putstr("minus ");
		ft_print_my_number(*dico_ref, argv[1]);
	}
	else
	{
		if (ft_check_input(argv[2]) != 0)
		{
			if (ft_check_input(argv[2]) == 2)
				ft_putstr("minus ");
			ft_print_my_number(*new_dico, argv[2]);
			while (++i < SDICO)
				free((*new_dico)[i].str_val);
			free(*new_dico);
		}
	}
}

int	main(int argc, char *argv[])
{
	int			i;
	t_dico_elem	*dico_ref;
	t_dico_elem	*new_dico;

	i = -1;
	if (argc == 1 || argc > 3)
		return (0);
	if (give_me_a_dico(argc, argv, &dico_ref, &new_dico) == 0)
		return (0);
	second(&dico_ref, &new_dico, argv, argc);
	while (++i < SDICO)
		free(dico_ref[i].str_val);
	free(dico_ref);
}
