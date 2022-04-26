/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <nadesjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 17:49:35 by raruiz-r          #+#    #+#             */
/*   Updated: 2022/02/28 11:39:25 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	ft_putchar(char c);

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
			if (((v == 1 && h == 1) || (v == y && h == 1))
				|| ((v == 1 && h == x) || (v == y && h == x)))
				ft_putchar('o');
			else if (v == 1 || v == y)
				ft_putchar('-');
			else if (h == 1 || h == x)
				ft_putchar('|');
			else
				ft_putchar(' ');
		h++;
		}
		ft_putchar('\n');
				v++;
	}
}
