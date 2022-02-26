/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_my_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 22:08:33 by lgiband           #+#    #+#             */
/*   Updated: 2022/02/20 20:31:51 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_centaine(t_uint number, t_uint len, t_dico_elem *dico, int *trigr)
{
	*trigr = 0;
	if (number / ft_power(10, len - 1) != 0)
	{
		ft_putdico(number / ft_power(10, len - 1), dico);
		*trigr = 1;
		ft_putstr(" ");
		ft_putdico(100, dico);
		if (number - ((number / ft_power(10, len - 1))
				* ft_power(10, len - 1)) != 0)
			ft_putstr(" and ");
		else if (len != 3)
			ft_putstr(" ");
	}
	cut_nb(number - ((number / ft_power(10, len - 1))
			* ft_power(10, len - 1)), len - 1, dico, trigr);
}

void	ft_dizaine(t_uint number, t_uint len, t_dico_elem *dico, int *trigr)
{
	if (number / ft_power(10, len - 1) != 0)
	{
		*trigr = 1;
		ft_putdico((number / ft_power(10, len - 1)) * 10, dico);
	}
	if (number / ft_power(10, len - 2) != 0)
		ft_putstr("-");
	else if (number / ft_power(10, len - 2) != 0)
		ft_putstr(" ");
	cut_nb(number - ((number / ft_power(10, len - 1))
			* ft_power(10, len - 1)), len - 1, dico, trigr);
}

void	ft_unite(t_uint number, t_uint len, t_dico_elem *dico, int *trigr)
{
	if (number / ft_power(10, len - 1) != 0)
	{
		ft_putdico(number / ft_power(10, len - 1), dico);
		*trigr = 1;
		if (len != 1)
			ft_putstr(" ");
	}
	if (len - 1 != 0 && *trigr == 1)
	{
		ft_putdico(ft_power(10, len - 1), dico);
		if (number - ((number / ft_power(10, len - 1))
				* ft_power(10, len - 1)) != 0)
			ft_putstr(", ");
	}
	cut_nb(number - ((number / ft_power(10, len - 1))
			* ft_power(10, len - 1)), len - 1, dico, trigr);
}

void	ft_dizaine_2(t_uint number, t_uint len, t_dico_elem *dico, int *trigr)
{
	ft_putdico((number / ft_power(10, len - 2)), dico);
	*trigr = 1;
	if (len - 2 != 0)
		ft_putstr(" ");
	if (len - 2 != 0)
	{
		ft_putdico(ft_power(10, len - 2), dico);
		if (number - ((number / ft_power(10, len - 2)) * ft_power(10, len - 2)))
			ft_putstr(" ");
	}
	cut_nb(number - ((number / ft_power(10, len - 2))
			* ft_power(10, len - 2)), len - 2, dico, trigr);
}

void	cut_nb(t_uint number, t_uint len, t_dico_elem *dico, int *trigr)
{
	if (len == 0)
		return ;
	if (len % 3 == 0)
		ft_centaine(number, len, dico, trigr);
	else if (len % 3 == 2)
	{
		if (ft_is_in_dico(number / ft_power(10, len - 2), dico)
			&& number / ft_power(10, len - 2) != 0)
			ft_dizaine_2(number, len, dico, trigr);
		else
			ft_dizaine(number, len, dico, trigr);
	}
	else if (len % 3 == 1)
		ft_unite(number, len, dico, trigr);
}