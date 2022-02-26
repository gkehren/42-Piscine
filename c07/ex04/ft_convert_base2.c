/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 09:49:17 by gkehren           #+#    #+#             */
/*   Updated: 2022/02/13 17:50:07 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_espace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

int	ft_base_test_atoi(char *str)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		if (c == '+' || c == '-' || ft_espace(c))
			return (0);
		j = i;
		while (str[++j])
			if (str[j] == c)
				return (0);
		i++;
	}
	return (i);
}

int	ft_base_nb(char *base, char c, int *base_result)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
		{
			*base_result = i;
			return (i);
		}
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_nbr;
	int	sign;
	int	result;
	int	base_result;

	base_nbr = ft_base_test_atoi(base);
	sign = 1;
	result = 0;
	base_result = 0;
	if (base_nbr < 2)
		return (0);
	while (ft_espace(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (ft_base_nb(base, *str++, &base_result) != -1)
		result = result * base_nbr + base_result;
	return (result * sign);
}
