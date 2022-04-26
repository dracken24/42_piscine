/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 23:47:06 by tparadis          #+#    #+#             */
/*   Updated: 2022/03/14 00:32:45 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	is_numeric(char c)
{
	if (c <= 57 && c >= 48)
		return (1);
	else
		return (0);
}

long long int	ft_atoi(char *number, int start)
{
	long long int	ret;
	int				i;
	long long int	index;

	ret = 0;
	index = 1;
	i = -1;
	while (number[++i] != '+' && !is_numeric(number[i]))
		if (number[i] != ' ' && number[i] != '	')
			return (-1);
	if (number[i] == '+' && !is_numeric(number[i + 1]))
		return (-1);
	start = i;
	if (number[i] == '+')
		start = i + 1;
	while (is_numeric(number[++i]))
		;
	while (is_numeric(number[--i]))
	{
		ret += index * (number[i] - 48);
		index *= 10;
	}
	if (ret > 4294967295)
		return (-1);
	return (start);
}

int	is_all_zero(char *number)
{
	int	i;

	i = 0;
	while (number[i])
	{
		if (number[i] != '0')
			return (0);
		i++;
	}
	return (i);
}
