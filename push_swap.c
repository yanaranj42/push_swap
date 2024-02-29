/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:26:32 by yanaranj          #+#    #+#             */
/*   Updated: 2024/02/29 18:38:27 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* i: iterador de argumentos.
 * flag: control si la lista esta vacia.
 * *tmp: lista temporal
 * *new_ring: nuevo nodo que se agrega al stack
 * WHILE: reservamos espacio para el nuevo nodo y control de error.
 * 		  Miramos que valor tiene y pasamos al siguiente arg.
 * 		  Tenemos la flag en 1 para indicar que es la primera entrada y por lo
 * 		  tanto el nuevo nodo esta al inicio de la lista.
 * 		  En caso de ya tener un inicio, agrega el nodo en la siguiente posicion
 * Para finalizar, indicamos que el siguiente nodo es nulo.
 * Guardamos la nueva lista en tmp.
 */
int	fill_stack(t_stack *a, int argc, char **argv)
{
	int	i;
	int	flag;
	t_ring	*tmp;
	t_ring	*new_ring;

	i = 1;
	flag = 1;
	while (i < argc)
	{
		new_ring = malloc(sizeof(t_ring));
		if (!new_ring)
			return (0);
		new_ring->value = ft_atoi(argv[i++]);
		if (flag == 1)
		{
			a->head = new_ring;
			flag = 0;
		}
		else
			tmp->next = new_ring;
		new_ring->next = NULL;
		tmp = new_ring;
	}
	return (0);
}

void	assign_index(t_ring *lst)
{
	t_ring	*tmp;
	t_ring	*first;
	int		indx;
	
	first = lst;
	while (lst)
	{
		indx = 0;
		tmp = first;
		while (tmp)
		{
			if (tmp->value < lst->value)
				indx++;
			tmp = tmp->next;
		}
		lst->index = indx;
		lst = lst->next;
	}
}

int main (int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_ring	*ptr;

	a.head = NULL;
	b.head = NULL;
	a.len = 0;
	b.len = 0;
	if (argc < 2 || arg_checker(argc, argv) == 1)
		return (0);
	fill_stack(&a, argc, argv);
	assign_index(a.head);
	print_stack(&a); //recibido
	if(stack_is_sorted(&a))
		return (0);
	ft_lstsize(&a);
	ft_lstsize(&b);
	sort_stack(&a, &b);
	ptr = a.head;
	print_stack(&a); //retornado y ordenado.
	free_ptr(ptr);
	return (0);
}
