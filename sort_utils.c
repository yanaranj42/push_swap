/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:15:47 by yanaranj          #+#    #+#             */
/*   Updated: 2024/02/29 18:38:23 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Miramos si el stack a esta ordenado. Para ello recorremos los nodos
 * (poniendo la lista en una variable temporal). 
 * WHILE: recorremos hasta el ultimo nodo
 * IF: si el indice es mayor al siguiente indice, la lista no esta ordenada.
 * Pasamos al siguiente nodo para continuar en el bucle. 
 * Retornamos 1 en caso de que este ordenado.
 */

int	stack_is_sorted(t_stack *a)
{
	t_ring	*tmp;

	tmp = a->head;
	while (tmp->next != NULL)
	{
		if (tmp->index > tmp->next->index)
		{	
			printf("\nNOT sorted\n");
			return (0);
		}
		tmp = tmp->next;
	}
	printf("\nIS sorted\n");
	return (1);
}

void	put_top(t_stack *a, int n)
{
	t_ring	*tmp;
	int		i;

	tmp = a->head;
	i = 0;
	while (tmp->index != n) //mientras el indice no sea el num pasado
	{
		tmp = tmp->next;//leemos el indice del siguiente nodo
		i++;//iterador de la lista
	}
	if (i < a->len / 2)//estta la lista el la primera mitad?
	{
		while (a->head->index != n)//rota tantas veces hasta que n
			rotate_a(a);//llegue a la primera posicion
	}
	else
	{
		while (a->head->index != n)//si esta en la 2a mitad, rota por abajo
			rev_rotate_a(a);//hasta que n llegue a la 1a posicion
	}
}

void	free_ptr(t_ring *ptr)
{
	t_ring	*tmp;

	while (ptr)
	{
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
}

void	print_stack(t_stack *a)
{
	t_ring		*tmp;

	tmp = a->head;
	while (tmp)
	{
		printf("\nvalue: %d\tindex: %d\n", tmp->value, tmp->index);
		tmp = tmp->next;
	}
}

