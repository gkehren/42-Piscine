/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:57:39 by nmathieu          #+#    #+#             */
/*   Updated: 2022/02/13 14:51:43 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

// Returns an `unsigned short` with its `n` first bits set to one.
t_ushort	ft_first_bits(t_uint n)
{
	return ((1 << n) - 1);
}

// Returns an `unsigned short` with its `n`th bit set to one.
t_ushort	ft_bit(t_uint n)
{
	return (1 << n);
}

// Returns whether the `n`th bit of x is set to 1.
int	ft_bit_is_one(t_ushort x, t_uint n)
{
	return ((x >> n) & 1);
}

t_uint	ft_count_ones(t_ushort x)
{
	t_uint	ones;

	ones = 0;
	while (x)
	{
		if (x & 1)
			ones++;
		x >>= 1;
	}
	return (ones);
}

// Sets the `n`th bit of `x` to 1.
void	ft_set_bit(t_ushort *x, t_uint n, int one)
{
	if (one)
		*x |= 1 << n;
	else
		*x &= ~(1 << n);
}
