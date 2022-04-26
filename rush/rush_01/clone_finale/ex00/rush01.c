/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:43:56 by tparadis          #+#    #+#             */
/*   Updated: 2022/03/06 22:01:08 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	**make_board(void);
int		check_tiles(int x, int y);
char	*check_args(char **argv);
int		str_size(char *str);
int		check_row(int nb, int y);
int		check_column(int nb, int x);
int		contains_n(char *arr, char c, int size, int index);
int		contains_column_n(char c, int column, int size, int index);
void	print_board(void);

int		g_size;
char	**g_board;
char	*g_rests;

int	main(int argc, char **argv)
{
	int	i;
	int	result;

	i = 0;
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	g_rests = check_args(argv);
	if (g_rests == NULL)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	g_size = str_size(g_rests) / 4;
	g_board = make_board();
	result = check_tiles(0, 0);
	if (result)
	{
		print_board();
	}
	else
		write(1, "Error\n", 6);
}

int	check_tiles(int x, int y)
{
	int	i;
	int	result;

	i = 0;
	while (++i <= g_size)
	{
		if (!contains_n(g_board[x], i + 48, g_size, y)
			&& !contains_column_n(i + 48, y, g_size, x))
		{
			g_board[x][y] = i + 48;
			if (y == g_size -1 && x == g_size -1
				&& check_row(x, y) && check_column(y, x))
				return (1);
			else if (y == g_size - 1
				&& x < g_size - 1 && check_row(x, y))
					result = check_tiles(x + 1, 0);
			else if (x == g_size - 1 && check_column(y, x))
					result = check_tiles(x, y + 1);
			else if (y < g_size && x < g_size - 1)
				result = check_tiles(x, y + 1);
			if (result == 1 && check_row(x, y) && check_column(y, x))
				return (1);
		}
	}
	return (0);
}

int	check_row(int nb, int y)
{
	int		i;
	int		count;
	char	last;

	i = -1;
	count = 0;
	last = 48;
	while (++i < g_size)
	{
		if (last < g_board[nb][i] && ++count != -1)
			last = g_board[nb][i];
	}
	if (count > g_rests[g_size * 2 + nb] - 48
		|| g_rests[g_size * 2 + nb] - 48 > count + (g_size - 1 - y))
		return (0);
	count = 0;
	last = 48;
	while (--i != -1)
	{
		if (last < g_board[nb][i] && ++count != -1)
			last = g_board[nb][i];
	}
	return (!(count > g_rests[g_size * 3 + nb] - 48
			|| g_rests[g_size * 3 + nb] - 48 > count + (g_size - 1 - y)));
}

int	check_column(int nb, int x)
{
	int		i;
	int		count;
	char	last;

	i = -1;
	count = 0;
	last = 48;
	while (++i < g_size)
	{
		if (last < g_board[i][nb] && ++count != -1)
			last = g_board[i][nb];
	}
	if (count > g_rests[nb] - 48 || count + (g_size - 1 - x) < g_rests[nb] - 48)
		return (0);
	last = 48;
	count = 0;
	while (--i != -1)
	{
		if (last < g_board[i][nb] && ++count != -1)
			last = g_board[i][nb];
	}
	return (!(count > g_rests[g_size + nb] - 48
			|| count + (g_size - 1 - x) < g_rests[g_size + nb] - 48));
}

char	**make_board(void)
{
	char	*ptr;
	char	**arr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ptr = malloc((g_size) * (g_size));
	arr = malloc((g_size) * 8);
	while (i < g_size)
	{
		arr[i] = ptr + i * (g_size);
		while (j < g_size)
		{
			*(arr[i] + j) = 48;
			j++;
		}
		j = 0;
		i++;
	}
	return (arr);
}
