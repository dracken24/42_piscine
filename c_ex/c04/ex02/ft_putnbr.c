/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <nadesjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:17:49 by nadesjar          #+#    #+#             */
/*   Updated: 2022/03/02 14:17:49 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char x)
{
	write(1, &x, 1);
}

void	ft_print(int nb)
{
	//printf("%d\n", nb);
	if (nb > 9)
		ft_print(nb / 10);
	//printf("%d\n", nb);
	ft_putchar((nb % 10) + '0');
}

void	ft_putnbr(int nb)
{
	if (nb < 0 && nb != -2147483648)
	{
		nb *= -1;
		ft_putchar('-');
	}
	if (nb && nb != -2147483648)
		ft_print(nb);
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	if (nb == 0)
		ft_putchar('0');
}
