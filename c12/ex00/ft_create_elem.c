/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:01:35 by gkehren           #+#    #+#             */
/*   Updated: 2022/02/22 11:14:57 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	elem->next = NULL;
	elem->data = data;
	return (elem);
}

#include <stdio.h>
int main()
{
	struct s_list elem;
	int a = 42;
	elem.data = &a;
	int *nbr = elem.data;
	printf("%d\n", *nbr);
	return 0;
}
