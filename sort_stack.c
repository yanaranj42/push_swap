/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:50:10 by yanaranj          #+#    #+#             */
/*   Updated: 2024/02/29 18:00:54 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_max3(t_stack *a)
{
	t_ring	*tmp;
	t_ring	*last;

	tmp = a->head->next;
	last = tmp->next;
	if (a->head->index > tmp->index && a->head->index > last->index)
		rotate_a(a);
	else if (tmp->index > a->head->index && tmp->index > last->index)
		rev_rotate_a(a);
	if (!stack_is_sorted(a))
		swap(a);
}

void	small_sort(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	put_top(a, 0);//subimos el indice 0 al principio
	push_b(a, b);//lo enviamos al stack_b
	if (a->len == 4)//si hay 4 elementos en la lista, repite lo anterior pero
	{
		put_top(a, 1);//esta vez con el indice 1
		push_b(a, b);
	}
	sort_max3(a);
	while (b->head)
	{
		printf("entreee\n");
		push_a(b, a);
	}
}

void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->len <= 3)
		sort_max3(a);
	else if (a->len == 4 || a->len == 5)
		small_sort(a, b);
	printf("el stack tiene [%d] indices\n", ft_lstsize(a));
//	else if (a->len > 5)
//		chunks_sort(a, b);
}
