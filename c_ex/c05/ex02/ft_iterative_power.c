/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <nadesjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:08:01 by nadesjar          #+#    #+#             */
/*   Updated: 2022/03/07 17:08:01 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_count(int nb, int power)
{
	int	numb;

	numb = nb;
	while (power-- != 1)
		numb = numb * nb;
	return (numb);
}

int	ft_iterative_power(int nb, int power)
{
	int	numb;

	if (power < 0)
		return (0);
	else if ((power && nb) == 0)
		return (1);
	else
	{
		numb = ft_count(nb, power);
		return (numb);
	}
	return (0);
}
