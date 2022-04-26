/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:59:08 by tparadis          #+#    #+#             */
/*   Updated: 2022/03/14 00:34:42 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char			*g_dict;
char			*g_snum;
long long int	g_numlist[33] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
	10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 30, 40, 50, 60, 70, 80, 90,
	100, 1000, 1000000, 1000000000, -2};
char			**g_argv;

int	does_contain(long long int num)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (g_numlist[i] != -2)
	{
		if (g_numlist[i] == num)
			count++;
		i++;
	}
	return (count);
}

void	find_number(char *num)
{
	int		i;
	int		highest;
	char	*number;

	highest = get_num_length(get_full_num(num));
	i = 0;
	if (highest == 1 && num[i] == '0')
	{
		print_num(get_number_word(0), highest, 0);
		return ;
	}
	while (i < get_full_num(num))
	{
		if (highest == 10)
			i += handle_stwenty(i, num, &highest);
		if (highest == 1)
			number = get_number_word(highest * (num[i] - 48));
		else
			number = get_number_word(highest);
		if (number != NULL)
			i += handle_normal(num, number, &highest, i);
		else
			i += handle_offset(num, &highest, i, number);
	}
}

long long int	read_num(char *str)
{
	int				i;
	long long int	total;
	long long int	pow;

	i = 0;
	pow = 1;
	total = -1;
	while (str[i] && str[i] != '\n' && is_numeric(str[i]))
	{
		i++;
	}
	if (i != 0)
		total = 0;
	i--;
	while (i > -1)
	{
		total += (str[i] - 48) * pow;
		pow *= 10;
		i--;
	}
	return (total);
}

void	init(int fildes, int filesize, char *name, int argc)
{
	name = "numbers.dict";
	if (argc == 3)
	{
		fildes = open(g_argv[1], O_RDONLY);
		name = g_argv[1];
	}
	else
		fildes = open("numbers.dict", O_RDONLY);
	if (ft_atoi(g_argv[argc - 1], 0) == -1)
	{
		write(1, "Error", 5);
		return ;
	}
	if (fildes == -1)
	{
		write(1, "Dict Error", 10);
		return ;
	}
	filesize = get_file_size(fildes);
	fildes = reset_file(name, fildes);
	g_dict = get_dict(filesize, fildes);
	g_snum = &g_argv[argc - 1][0];
	find_number(&g_argv[argc - 1][0]);
}

int	main(int argc, char **argv)
{
	int		fildes;
	int		filesize;
	char	*name;

	fildes = 0;
	filesize = 0;
	name = NULL;
	if (argc >= 2 && argc <= 3)
	{
		g_argv = argv;
		init(fildes, filesize, name, argc);
		write(1, "\n", 1);
		free(g_dict);
	}
	return (0);
}
