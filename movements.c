/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:56:26 by yanaranj          #+#    #+#             */
/*   Updated: 2024/02/29 16:35:01 by yanaranj         ###   ########.fr       */
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
	t_ring	*tmp2;
	t_ring	*last;

	tmp = a->head;
	last = tmp;
	if (a == NULL || (a->head == NULL))
		return ;
	while (last->next != NULL)
	{	
		tmp2 = last;
		if (last->next != NULL)
			last = last->next;
	}
	last->next = tmp;
	a->head = last;
	tmp2->next = NULL;
	write(1, "rra\n", 4);
}

void	swap(t_stack *lst)
{
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

void	push_b(t_stack *a, t_stack *b)
{
	t_ring	*tmp;

	tmp = a->head;
	a->head = tmp->next; //decimos que el primer nodo pasa a ser el siguiente
	if (b->head == NULL)//stack b esta vacio, pero agregamos nodo
		tmp->next = NULL;//y next pasa a ser NULL;
	else
		tmp->next = b->head;
	b->head = tmp;
	b->len++;
	a->len--;//restamos el nodo en el stack a y se lo sumamos al b
	write(1, "pb\n", 3);
}

void	push_a(t_stack *b, t_stack *a)
{
	t_ring	*tmp;

	tmp = b->head;
	b->head = tmp->next;
	if (a->head == NULL)
		tmp->next  = NULL;
	else
		tmp->next = a->head;
	a->head = tmp;
	a->len++;
	b->len--;
	write(1, "pa\n", 3);
}
