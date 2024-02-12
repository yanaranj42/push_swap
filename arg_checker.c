/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:41:40 by yanaranj          #+#    #+#             */
/*   Updated: 2024/02/12 15:47:51 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

/* ERROR es una flag que tenemos al momento de checkear los inputs
 */

int is_limits(char *input)
{
	int error;

	error = 0;
	if (input[0] == '-')
	{
		if (ft_strlen(input) < 12)
			return (0);
		if (ft_strlen(input) > 11)
			return (1);
			//error = 1;
		if (ft_strncmp(input, "-2147483648", 11) > 0)
			return (1);
			//error = 1;
	}
	else
	{
		if (ft_strlen(input) < 10)
			return (0);
		if (ft_strlen(input) > 10)
			return (1);
			//error = 1;
		if (ft_strncmp(input, "2147483647", 10) > 0)
			return (1);
			//error = 1;
	}
	return (0);
}

int is_dup(int argc, char **argv)
{
	int	i;
	int	j;
	int error;

	i = 1;
	error = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[j]) == ft_atoi(argv[i]))
					error = 1;
			j++;
		}
		i++;
	}
	return (error);
}

int	is_digit(int error, int i, int j, char **argv)
{
	if (error == 0)
	{
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				error = 1;
				break ;
			}

		}
	}
	return (error);
}

int check_syntax(int argc, char **argv)
{
	int	i;
	int	j;
	int error;

	error = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == '\0')
			error = 1;
		else if (argv[i][0] == '-' || argv[i][0] == '+')
		{
			i++;
			if (argv[i][1] == '\0')
				error = 1;
		}
		if (error != '\0')
			error = is_digit(error, i, j, argv);
		i++;
	}
	return (error);
}


int arg_checker(int argc, char **argv)
{
	int error;
	int	i;

	error = 0;
	if (check_syntax (argc, argv) == 1)
		error = 1;
	if (is_dup(argc, argv) == 1)
		error = 1;
	i = 1;
	while (i < argc)
	{
		if (is_limits(argv[i]))
			error = 1;
		i++;
	}
	if (error == 1)
		write (2, "Error\n", 6);
	return (error);
}
