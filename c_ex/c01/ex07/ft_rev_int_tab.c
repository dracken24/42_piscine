/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <nadesjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:37:18 by nadesjar          #+#    #+#             */
/*   Updated: 2022/02/24 10:37:58 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	x;

	x = 0;
	size--;
	while (x < size)
	{
		temp = tab[size];
		tab[size] = tab[x];
		tab[x] = temp;
		x++;
		size--;
	}	
}
