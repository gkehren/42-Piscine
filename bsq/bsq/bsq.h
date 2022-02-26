/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:42:20 by gkehren           #+#    #+#             */
/*   Updated: 2022/02/22 11:44:28 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct s_pos
{
	char	x;
	char	y;
}	t_pos;

typedef struct s_max_pos
{
	t_pos	pos;
	int		c;
}	t_max_pos;

typedef struct s_legal
{
	char		e;
	char		o;
	char		f;
	long		i_max;
	long		j_max;
	long		t;
	long long	obc;
}	t_legal;

#endif
