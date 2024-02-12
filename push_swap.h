/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:14:18 by yanaranj          #+#    #+#             */
/*   Updated: 2024/02/12 15:41:26 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#ifndef PUSH_SWAP_H 
//# define PUSH_SWAP_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_ring
{
	int				value;
	int				index;
	struct s_ring	*next;
}	t_ring;

typedef struct s_stack
{
	int				length;
	t_ring			*start;
	struct s_ring	*last;
}	t_stack;

//		--PUSH SWAP--		//

int		main(int argc, char **argv);

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