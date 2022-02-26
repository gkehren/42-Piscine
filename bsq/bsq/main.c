/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmalatia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 07:28:57 by jmalatia          #+#    #+#             */
/*   Updated: 2022/02/22 07:28:58 by jmalatia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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

int	ft_taille(char *str, int i)
{
	while (*str != '\n')
		str++;
	str++;
	while (*str != '\n')
	{
		i++;
		str++;
	}
	return (i);
}

int	ft_atoi(char *str)
{
	int	c;
	int	fini;

	c = 1;
	fini = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			c *= -1;
			++str;
		}
		if (*str == '+')
			++str;
	}
	while (*str <= '9' && *str >= '0')
	{
		fini = fini * 10 + *str - '0';
		++str;
	}
	return (fini *= c);
}

int	ft_veriflab(char *str, t_legal lab, int *pt)
{
	if (str[lab.t] != lab.o && str[lab.t] != lab.e)
		*pt = -1;
	if (str[lab.t] == lab.o)
		return (1);
	return (0);
}

t_legal	ft_tabpull(t_legal lab, char *str, int *pt)
{
	while (str[lab.t] <= '9' && str[lab.t] >= '0')
	{
		lab.i_max = lab.i_max * 10 + str[lab.t] - '0';
		++lab.t;
	}
	if (str[lab.t] <= '~' && str[lab.t] >= ' ')
	{
		lab.e = str[lab.t];
		lab.t++;
	}
	if (str[lab.t] <= '~' && str[lab.t] >= ' ' && str[lab.t] != lab.e)
	{
		lab.o = str[lab.t];
		lab.t++;
	}
	if (str[lab.t] <= '~' && str[lab.t] >= ' ' && str[lab.t] != lab.e
		&& str[lab.t] != lab.o)
	{
		lab.f = str[lab.t];
		lab.t++;
	}
	if (str[lab.t] != '\n')
		*pt = -1;
	return (lab);
}

t_legal	ft_stplab(t_legal lab, char *str)
{
	lab.t = 0;
	lab.i_max = 0;
	lab.obc = 0;
	lab.j_max = ft_taille(str, 0);	
	return (lab);
}

t_legal	ft_tabwh(t_legal lab, char *str, int *pt, int i)
{
	while (!(str[lab.t] == '\n' || str[lab.t] == 0))
	{
		lab.obc += ft_veriflab(str, lab, pt);
		++i;
		lab.t++;
	}
	if (lab.j_max != i)
		*pt = -1;
	return (lab);
}

t_legal	ft_islegal(char *str, int *pt)
{
	long	x;
	t_legal	lab;

	lab = ft_stplab(lab, str);
	x = 0;
	lab = ft_tabpull(lab, str, pt);
	while (x < lab.i_max)
	{
		lab.t++;
		lab = ft_tabwh(lab, str, pt, 0);
		if (*pt == -1)
			return (lab);
		x++;
	}
	if ((str[lab.t] != 0) || (lab.obc == 0))
		*pt = -1;
	return (lab);
	}

void	ft_errortab(void)
{
	write(1, "maperror\n", 9);
	return ;
}

int	main(int argc, char **argv)
{
	char	*init;
	int		t;
	int		*pt;
	char	**tab;

	t = 0;
	pt = &t;
	init = "9.ox\n...........................\n....o......................\n............o..............\n...........................\n....o......................\n...............o...........\n...........................\n......o..............o.....\n..o.......o................\0";
	ft_islegal(init, pt);
	if (t == -1)
	{
		ft_errortab();
		return (0);
	}
	(void)argc;
	(void)argv;
	(void)tab;
	return (0);
}
