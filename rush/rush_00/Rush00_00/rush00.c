/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <nadesjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:33:24 by nadesjar          #+#    #+#             */
/*   Updated: 2022/02/26 14:33:24 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char x);

void	print(int x, char first, char middle, char last)
{
	int	letter;

	letter = 2;
	ft_putchar(first);
	while (letter < x)
	{
		ft_putchar(middle);
		letter++;
	}
	ft_putchar(last);
	ft_putchar('\n');
}

int	rush(int x, int y)
{
	int	line;

	line = 2;
	if (x < 1 || y < 1)
		return (0);
	print(x, 'o', '-', 'o');
	while (y >= 2 && line < y)
	{
		print(x, '|', ' ', '|');
		line++;
	}
	print(x, 'o', '-', 'o');
	return (0);
}
