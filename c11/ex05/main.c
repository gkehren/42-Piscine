/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:11:52 by gkehren           #+#    #+#             */
/*   Updated: 2022/02/18 10:21:42 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);

int	ft_atoi(char *str)
{
	int	i;
	int	mult;
	int	nb;

	i = 0;
	mult = 1;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mult *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	nb *= mult;
	return (nb);
}

int	ft_op_test(char *str)
{
	int	i;
	int	op;

	i = 0;
	op = 0;
	while (str[i] != '\0')
	{
		if (str[0] == '+' || str[0] == '-' || str[0] == '/'
			|| str[0] == '*' || str[0] == '%')
			op = 1;
		i++;
	}
	if (op == 1 && i == 1)
		return (1);
	else
		return (0);
}

int	ft_op(char *op, int a, int b)
{
	if (op[0] == '+')
		ft_putnbr(a + b);
	if (op[0] == '-')
		ft_putnbr(a - b);
	if (op[0] == '/')
	{
		if (b == 0)
		{
			write(1, "Stop : division by zero", 23);
			return (0);
		}
		ft_putnbr(a / b);
	}
	if (op[0] == '*')
		ft_putnbr(a * b);
	if (op[0] == '%')
	{
		if (b == 0)
		{
			write(1, "Stop : modulo by zero", 21);
			return (0);
		}
		ft_putnbr(a % b);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	a;
	int	b;
	int	(*ptr)(char *, int, int);

	ptr = ft_op;
	if (argc != 4)
		return (0);
	if (ft_op_test(argv[2]) == 0)
	{
		write(1, "0\n", 2);
		return (0);
	}
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	(*ptr)(argv[2], a, b);
	write(1, "\n", 1);
	return (0);
}
