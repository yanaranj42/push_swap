/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:50:10 by yanaranj          #+#    #+#             */
/*   Updated: 2024/02/23 17:50:07 by yanaranj         ###   ########.fr       */
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
	if (tmp->index > a->head->index && tmp->index > last ->index)
	{
		printf("rev_rot\n");
		rev_rotate_a(a);
	}
	if (a->head->index > tmp->index)
	{
		printf("swap\n");
		swap(a);
	}
}
/*
void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->len <= 3)
		sort_max3(a);
	else if (a->len == 4 || a->len == 5)
		small_sort(a, b);
	else if (a->len > 5)
		chunks_sort(a, b);
}
*/
void	sort_stack(t_stack *a)
{
	if (a->len <= 3)
		sort_max3(a);
	printf("el stack tiene [%d] indices\n", ft_lstsize(a));
}
