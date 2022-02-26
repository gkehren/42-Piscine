/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_my_number3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:18:48 by gkehren           #+#    #+#             */
/*   Updated: 2022/02/20 20:20:44 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_print_my_number(t_dico_elem *dico, char *number)
{
	unsigned int	int_number;
	unsigned int	len_number;
	int				trigger;

	int_number = ft_atoi(number);
	if (int_number == 0)
		ft_putdico(0, dico);
	len_number = ft_intlen(int_number);
	trigger = 0;
	cut_nb(int_number, len_number, dico, &trigger);
	ft_putstr("\n");
}
