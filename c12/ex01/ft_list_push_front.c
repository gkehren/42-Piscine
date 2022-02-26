/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:15:46 by gkehren           #+#    #+#             */
/*   Updated: 2022/02/23 10:16:19 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*elem;
	elem = malloc(sizeof(t_list));
	elem->data = data;
	elem->next = &begin_list[0];
}

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
	t_list tab[3][1];
	t_list elem;
	elem.data = "elem";
	t_list elem1;
	elem.data = "elem1";
	t_list elem2;
	elem.data = "elem2";
	elem.next = &elem1;
	elem1.next = &elem2;
	elem2.next = NULL;
	tab[0] = elem;
	tab[1] = elem1;
	tab[2] = elem2;

	ft_list_push_front(tab, "elem0");
	printf("%p\n", tab[0].data);
	return 0;
}