/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:14:18 by yanaranj          #+#    #+#             */
/*   Updated: 2024/02/23 17:34:32 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H 
# define PUSH_SWAP_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_ring
{
	int				value;//valor del argumento
	int				index;//posicion del argumento
	struct s_ring	*next;
}	t_ring;

typedef struct s_stack
{
	int				len;//longitud del la lista
	t_ring			*head;//inicio de la lista
	t_ring			*last;
}	t_stack;

//		--PUSH SWAP--		//
int		main(int argc, char **argv);
int		fill_stack(t_stack *a, int argc, char **argv);
void	assign_index(t_ring *node);

//		--SORT UTILIS--		//
int		stack_is_sorted(t_stack *a);
int		ft_lstsize(t_stack *lst);
void	print_stack(t_stack *a);

//		--SORT STACK__		//
void	sort_max3(t_stack *a);
//void	sort_stack(t_stack *a, t_stack *b);
void	sort_stack(t_stack *a);

//		--ARGV CHECKER--		//
int		arg_checker(int argc, char **argv);
int		check_syntax(int argc, char **argv);
int		is_digit(int error, int i, int j, char **argv);
int		is_dup(int argc, char **argv);
int		is_limits(char *input);

//		--LIBFT UTILS--		//
size_t	ft_strlen(const char *c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_atoi(const char *str);
int	ft_isdigit(int c);

//		--MOVEMENTS--		//
void	rotate_a(t_stack *a);
void	rev_rotate_a(t_stack *a);
void	swap(t_stack *lst);

#endif
