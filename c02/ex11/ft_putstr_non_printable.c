/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:14:40 by gkehren           #+#    #+#             */
/*   Updated: 2022/02/07 09:46:29 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_dec_hex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (c > 16)
	{
		ft_dec_hex(c / 10);
		ft_dec_hex(c % 10);
	}
	else
	{
		c = hex[(int) c];
		ft_putchar(c);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < 32 && str[i] > 0) || str[i] == 127)
		{
			ft_putchar('\\');
			if (str[i] < 16)
				ft_putchar('0');
			ft_dec_hex(str[i]);
		}
		else
		{
			ft_putchar(str[i]);
		}
		i++;
	}
}
/*
int	main()
{
	char	tab[] = "Coucou\rtu vas bien ?";
	ft_putstr_non_printable(tab);
}*/
