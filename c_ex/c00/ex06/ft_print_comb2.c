/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <nadesjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:16:14 by nadesjar          #+#    #+#             */
/*   Updated: 2022/02/24 14:20:22 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_print_nbr(int *a, int *b)
{
	ft_putchar((*a / 10) + '0');
	ft_putchar((*a % 10) + '0');
	ft_putchar(' ');
	ft_putchar((*b / 10) + '0');
	ft_putchar((*b % 10) + '0');
	if (!(*a == 98 && *b == 99))
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = 1;
		while (b <= 99)
		{
			if (a < b)
				ft_print_nbr(&a, &b);
			b++;
		}
		a++;
	}
}
