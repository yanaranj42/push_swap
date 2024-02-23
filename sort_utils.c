/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:15:47 by yanaranj          #+#    #+#             */
/*   Updated: 2024/02/23 16:50:52 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Miramos si el stack a esta ordenado. Para ello recorremos los nodos (poniendo la lista en una variable temporal). 
 * WHILE: recorremos hasta el ultimo nodo
 * IF: si el indice es mayor al siguiente indice, la lista no esta ordenada.
 * Pasamos al siguiente nodo para continuar en el bucle. 
 * Retornamos 1 en caso de que este ordenado.
 */

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

int	stack_is_sorted(t_stack *a)
{
	t_ring	*tmp;

	tmp = a->head;
	while (tmp->next != NULL)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	printf("stack is sorted");
	return (1);
}

int	ft_lstsize(t_stack *stack)
{
	int		lst_len;
	t_ring	*lst;

	lst_len = 0;
	lst = stack->head;
	while (lst->next)
	{
		lst = lst->next;
		lst_len++;
	}
	stack->len = lst_len + 1;
	return (lst_len);
}
