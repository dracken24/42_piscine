/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <nadesjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 22:12:54 by raruiz-r          #+#    #+#             */
/*   Updated: 2022/03/01 11:35:36 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_linefill(int v, int h, int x, int y)
{
	if ((h == 1 && v == 1) || (v == y && h == x))
		ft_putchar('A');
	else if ((v == 1 && h == x) || (v == y && h == 1))
		ft_putchar('C');
	else if ((h == 1 || h == x) && (v > 1 && v < y))
		ft_putchar('B');
	else if ((h > 1 && h < x) && (v == 1 || v == y))
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	v;
	int	h;

	if (x <= 0 || y <= 0)
		return ;
	v = 1;
	while (v <= y)
	{
	h = 1;
		while (h <= x)
		{
			ft_linefill(v, h, x, y);
		h++;
		}
		ft_putchar('\n');
	v++;
	}
}
