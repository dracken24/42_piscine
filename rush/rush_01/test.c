/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <nadesjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:22:57 by nadesjar          #+#    #+#             */
/*   Updated: 2022/03/06 12:29:40 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10);
		ft_putchar('8');
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else
	{
		if (nb > 9)
		{
			ft_putnbr(nb / 10);
		}
		ft_putchar(48 + nb % 10);
	}
}

void	ft_print_board(int board[6][6])
{
	int	row;
	int	col;

	row = 1;
	while (row < 5)
	{
		col = 1;
		while (col < 5)
		{
			ft_putnbr(board[row][col]);
			ft_putchar(32);
			col++;
		}
		row++;
		ft_putchar('\n');
	}
}

int	ft_in_row(int board[6][6], int number, int row)
{
	int	i;

	ft_putstr("in row ? : ");
	i = 1;
	while (i < 5)
	{
		if (board[row][i] == number)
		{
			ft_putstr("false\n");
			return (0);
		}
		else
		{
			i++;
		}
	}
	ft_putstr("true\n");
	return (1);
}

int	ft_in_col(int board[6][6], int number, int col)
{
	int	i;

	ft_putstr("in col ? : ");
	i = 1;
	while (i < 5)
	{
		if (board[i][col] == number)
		{
			ft_putstr("false\n");
			return (0);
		}
		else
		{
			i++;
		}
	}
	ft_putstr("true\n");
	return (1);
}

int	ft_is_valid(int *board[6][6], int number, int row, int col)
{
	int	vrow;
	int	vcol;

	vrow = ft_in_row(board, number, row);
	vcol = ft_in_col(board, number, col);
	ft_putstr("valid placement ?\n ");
	if ((vrow + vcol) > 1)
	{
		ft_putstr(" true\n");
		return (1);
	}
	else
	{
		ft_putstr(" false\n");
		return (0);
	}
}

int	ft_solve(int board[6][6])
{
	int	row;
	int	col;
	int	number_to_try;

	row = 1;
	number_to_try = 1;
	while (row <= 5)
	{
		col = 0;
		while (col <= 5)
		{
			if (board[row][col] == 0)
			{
				while (number_to_try <= 4)
				{
					if (ft_is_valid(board, number_to_try, row, col))
					{
						board[row][col] = number_to_try;
						if (ft_solve(board))
						{
							return (1);
						}
						else
						{
							board[row][col] = 0;
						}
					}
					number_to_try++;
				}
			}
			col++;
		}
		row++;
	}
	return (1);
}

int	main(void)
{
	int board[6][6] = 
	{
		{0, 4, 3, 2, 1, 0},
		{4, 0, 0, 0, 0, 1},
		{3, 0, 0, 0, 0, 2},
		{2, 0, 0, 0, 0, 2},
		{1, 0, 0, 0, 0, 2},
		{0, 1, 2, 2, 2, 0},
	};

	ft_print_board(board);
	if (ft_solve(board))
	{
		ft_putstr("\n Résolu !!! \n");
	}
	else
	{
		ft_putstr("\n Impossible! \n");
	}
	ft_print_board(board);
	return (0);
}
