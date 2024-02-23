/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:56:26 by yanaranj          #+#    #+#             */
/*   Updated: 2024/02/23 17:39:32 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *a)
{
	t_ring	*tmp;
	t_ring	*last;

	tmp = a->head;
	last = tmp;
	if (a == NULL || (a->head == NULL))
		return ;
	while (last ->next != NULL)
		last = last->next;
	a->head = tmp->next;
	last->next = tmp;
	tmp->next = NULL;
	write(1, "ra\n", 3);
}

void	rev_rotate_a(t_stack *a)
{
	t_ring	*tmp;
	t_ring	*last;

	tmp = a->head;
	last = tmp;
	if (a == NULL || (a->head == NULL))
		return ;
	while (tmp->next != NULL)
		tmp = tmp->next;
	last->next = NULL;
	tmp->next = a->head;
	a->head = tmp;
	write(1, "rra\n", 4);
}

void	swap(t_stack *lst)
{
	printf("lo intento");
	t_ring	*tmp;
	t_ring	*swap;

	tmp = lst->head;
	swap = tmp;
	tmp = tmp->next;
	swap->next = tmp->next;
	tmp->next = tmp->next;
	tmp->next = swap;
	lst->head = tmp;
	write(1, "sa\n", 3);
}
