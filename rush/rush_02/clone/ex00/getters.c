/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 23:46:41 by tparadis          #+#    #+#             */
/*   Updated: 2022/03/13 23:46:43 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	get_full_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] && is_numeric(str[i]))
		i++;
	return (i);
}

int	get_num_length(int nb)
{
	int	i;
	int	total;

	total = 1;
	i = 0;
	if (nb == 0)
		return (0);
	while (i < nb - 1)
	{
		total *= 10;
		i++;
	}
	return (total);
}

int	get_offset(int number)
{
	int	count;
	int	last;
	int	i;

	i = -1;
	last = 0;
	count = 0;
	while (g_dict[++i])
	{
		if (i == 0 || g_dict[i] == '\n')
		{
			if (i != 0)
				i++;
			while (g_dict[i] && g_dict[i] != ':' && g_dict[i] != '\n')
			{
				count++;
				i++;
			}
			i--;
			if (count < number && count >= last)
				last = count;
			count = 0;
		}
	}
	return (number - last);
}

int	get_index_from_highest(int highest)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i != highest)
	{
		i *= 10;
		j++;
	}
	return (j);
}
