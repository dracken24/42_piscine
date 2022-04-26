/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_test_2x2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:17:12 by nadesjar          #+#    #+#             */
/*   Updated: 2022/03/21 13:58:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str);
int ft_check_entry(char *strnb);
void ft_put_checker();
int ft_check_row(int x, int y);
void ft_print_board();

char	g_list[17];
int g_board[6][6] = {
	{'0', '0', '0', '0', '0', '0'},
	{'0', '0', '0', '0', '0', '0'},
	{'0', '0', '0', '0', '0', '0'},
	{'0', '0', '0', '0', '0', '0'},
	{'0', '0', '0', '0', '0', '0'},
	{'0', '0', '0', '0', '0', '0'}};

int main(int argc, char **argv)
{
	int	a;
	int	k;
	int x;
	int y;
	char nb_entry[17];

	x = 1;
	y = 1;
	if (argc != 2)
		{
			write(1, "Wrong entry\n", 12);
			return (0);
		}
	ft_check_entry(argv[1]);
	if (ft_check_entry(argv[1]) == 0)
	{
		write(1, "Numbers invalid\n", 16);
		return (0);
	}
	ft_put_checker();
	ft_check_row(x, y);
	ft_print_board();
	return (0);
}

int	ft_check_row(int x, int y)
{
	while (x <= 4)
	{
		while (y <= 4)
		{
			if (g_board[1][0] && g_board[0][1] == '1')
			{
				g_board[1][1] = '4';
			}
			y++;
		}
		x++;
	}
}

void	ft_print_board()
{
	int i;
	int k;

	i = 0;
	while (i < 6)
	{
		k = 0;
		while (k < 6)
		{
			write(1, &g_board[i][k], 1);
			k++;
		}
		i++;
		write (1, "\n",1);
	}
}

int	ft_check_entry(char *strnb)
{
	int		i;
	int		k;
	int		x;

	i = 0;
	k = 1;
	x = 0;
	if (ft_strlen(strnb) != 31)
		return (0);
	while (strnb[i] != '\0')
	{
		if (strnb[i] >= '1' && strnb[i] <= '4' && k == 1)
		{
			g_list[x] = strnb[i];
			x++;
			k = 0;
		}
		else if (strnb[i] == ' ' && k == 0)
			k = 1;
		else
			return (0);
		i++;
	}
	if (ft_strlen(g_list) == 16)
	{
		//printf("%s\n", g_list);
		return (1);
	}
	return (0);
}

void	ft_put_checker()
{
	g_board[0][1] = g_list[0];
	g_board[0][2] = g_list[1];
	g_board[0][3] = g_list[2];
	g_board[0][4] = g_list[3];

	g_board[5][1] = g_list[4];
	g_board[5][2] = g_list[5];
	g_board[5][3] = g_list[6];
	g_board[5][4] = g_list[7];

	g_board[1][0] = g_list[8];
	g_board[2][0] = g_list[9];
	g_board[3][0] = g_list[10];
	g_board[4][0] = g_list[11];

	g_board[1][5] = g_list[12];
	g_board[2][5] = g_list[13];
	g_board[3][5] = g_list[14];
	g_board[4][5] = g_list[15];
}

int ft_strlen(char *str)
{
	int x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}
