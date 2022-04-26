/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <nadesjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:58:39 by nadesjar          #+#    #+#             */
/*   Updated: 2022/03/08 16:42:23 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	count;

	count = 1;
	i = 1;
	if (nb < 0)
		return (0);
	if (nb <= 1)
		return (1);
	while (nb >= i)
	{
		count = count * i;
		i++;
	}
	return (count);
}
