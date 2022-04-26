/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <nadesjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:43:56 by tparadis          #+#    #+#             */
/*   Updated: 2022/03/06 17:12:18 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
char **
make_board(void);
int check_tiles(int x, int y);
char *check_args(int argc, char **argv);
int str_size(char *str);
int check_row(int nb, int y);
int check_column(int nb, int x);
int contains_n(char *arr, char c, int size, int index);
int contains_column_n(char c, int column, int size, int index);
int g_size;
char **g_board;
char *g_rests;
int main(int argc, char **argv)
{
	int i;

	i = 0;
	g_rests = check_args(argc, argv);
	if (g_rests == NULL)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	g_size = str_size(g_rests) / 4;
	g_board = make_board();
	check_tiles(0, 0);
	while (i < g_size)
	{
		printf("%.*s", g_size, g_board[i]);
		printf("\n");
		i++;
	}
}
int check_tiles(int x, int y)
{
	int i;
	int result;
	
		i = 1;
	while (i <= g_size)
	{
		if (!contains_n(g_board[x], i + 48, g_size, y) && !contains_column_n(i + 48, y, g_size, x))
		{
			g_board[x][y] = i + 48;
			if (y == g_size - 1 && x == g_size - 1)
			{
				if (check_row(x, y) && check_column(y, x))
					return (1);
			}
			else if (y == g_size - 1 && x < g_size - 1)
			{
				if (check_row(x, y))
					result = check_tiles(x + 1, 0);
			}
			else if (x == g_size - 1)
			{
				if (check_column(y, x))
					result = check_tiles(x, y + 1);
			}
			else if (y < g_size && x < g_size - 1)
				result = check_tiles(x, y + 1);
			if (result == 1 && check_row(x, y) && check_column(y, x))
				return (1);
		}
		i++;
	}
	return (0);
}
int check_row(int nb, int y)
{
	int i;
	int count;
	char last;
	
		i = -1;
	count = 0;
	last = 48;
	while (++i < g_size)
	{
		if (last < g_board[nb][i])
		{
			count++;
			last = g_board[nb][i];
		}
	}
	if (count > g_rests[g_size * 2 + nb] - 48 || g_rests[g_size * 2 + nb] - 48 > count + (g_size - 1 - y))
		return (0);
	count = 0;
	last = 48;
	while (--i != -1)
	{
		if (last < g_board[nb][i])
		{
			count++;
			last = g_board[nb][i];
		}
	}
	if (count > g_rests[g_size * 3 + nb] - 48 || g_rests[g_size * 3 + nb] - 48 > count + (g_size - 1 - y))
		return (0);
	return (1);
}
int check_column(int nb, int x)
{
	int i;
	int count;
	char last;

	i = -1;
	count = 0;
	last = 48;
	while (++i < g_size)
	{
		if (last < g_board[i][nb])
		{
			count++;
			last = g_board[i][nb];
		}
	}
	if (count > g_rests[nb] - 48 || count + (g_size - 1 - x) < g_rests[nb] - 48)
		return (0);
	last = 48;
	count = 0;
	while (--i != -1)
	{
		if (last < g_board[i][nb])
		{
			count++;
			last = g_board[i][nb];
		}
	}
	if (count > g_rests[g_size + nb] - 48 || count + (g_size - 1 - x) < g_rests[g_size + nb] - 48)
		return (0);
	return (1);
}
char **make_board(void)
{
	char *ptr;
	char **arr;
	int i;
	int j;

	i = 0;
	j = 0;
	ptr = malloc((g_size) * (g_size));
	arr = malloc((g_size)*8);
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
char *check_args(int argc, char **argv)
{
	int i;
	char *numlist;

		i = 0;
	numlist = malloc(64);
	if (argc != 2)
		return (NULL);
	while (*argv[1] != 0)
	{
		if (*argv[1] >= 48 && *argv[1] <= 57)
		{
			numlist[i] = *argv[1];
			i++;
		}
		else if (*argv[1] != ' ')
			return (NULL);
		argv[1]++;
	}
	numlist[i] = 0;
	if (i % 4 != 0)
		return (NULL);
	return (numlist);
}
int str_size(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
int contains_n(char *arr, char c, int size, int index)
{
	int i;
	int count;

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
int contains_column_n(char c, int column, int size, int index)
{
	int i;
	int count;

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
