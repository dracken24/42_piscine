/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <nadesjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:52:51 by nadesjar          #+#    #+#             */
/*   Updated: 2022/02/24 17:20:49 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_print_nbr(int nbr)
{
	int	x;

	x = 0;
	if (nbr > 9)
		ft_print_nbr(nbr / 10);
	x = nbr % 10 + '0';
	ft_putchar(x);
}

void	ft_putnbr(int nb)
{
	if (nb != -2147483648)
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = nb * -1;
		}
		if (nb)
		{
			ft_print_nbr(nb);
		}
	}
	else if (nb == -2147483648)
		write(1, "-2147483648", 11);
}
