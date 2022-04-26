/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 20:44:36 by tparadis          #+#    #+#             */
/*   Updated: 2022/03/06 21:01:30 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

extern int	g_size;
extern char	**g_board;
extern char	*g_rests;

char	*check_args(char **argv)
{
	int		i;
	char	*numlist;
	char	lc;

	i = 0;
	numlist = malloc(64);
	lc = ' ';
	while (*argv[1] != 0)
	{
		if (*argv[1] >= 48 && *argv[1] <= 57)
		{
			numlist[i] = *argv[1];
			i++;
		}
		else if (*argv[1] != ' ')
			return (NULL);
		if (lc == *argv[1] || (lc >= 48 && *argv[1] >= 48))
			return (NULL);
		lc = *argv[1];
		argv[1]++;
	}
	numlist[i] = 0;
	if (i % 4 != 0 || lc == ' ')
		return (NULL);
	return (numlist);
}

int	str_size(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	contains_n(char *arr, char c, int size, int index)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (arr[i] && i < index && i < size)
	{
		if (arr[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	contains_column_n(char c, int column, int size, int index)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < index && i < size)
	{
		if (c == g_board[i][column])
			count++;
		i++;
	}
	return (count);
}

void	print_board(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < g_size)
	{
		while (j < g_size)
		{
			write(1, &g_board[i][j], 1);
			if (j != g_size - 1)
				write(1, " ", 1);
			j++;
		}
		j = 0;
		write(1, "\n", 1);
		i++;
	}
}
