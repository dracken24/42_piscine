/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 23:46:06 by tparadis          #+#    #+#             */
/*   Updated: 2022/03/14 00:34:55 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	print_multiple(int multi)
{
	char	*number;

	number = get_number_word(multi);
	print_num(number, multi, 0);
}

void	print_unit(char c, char *number, int highest)
{
	int		i;
	char	*unit;

	i = 0;
	if (c > 47 && c <= 57)
	{
		if (c != 48)
		{
			unit = get_number_word(c - 48);
			print_num(unit, highest, 0);
			if (highest != 1)
			i = 0;
		}
		if (highest != 1)
			print_num(number, highest, 0);
	}
}

void	print_num(char *number, int highest, int offset)
{
	int	i;

	(void)highest;
	(void)offset;
	i = 0;
	while (number[i] && number[i] != '\n')
	{
		write(1, &number[i], 1);
		i++;
	}
	write(1, " ", 1);
}

int	print_offset(int offset, char *num, int highest)
{
	int		number;
	char	*printnum;
	int		retval;

	number = (num[0] - 48);
	retval = 0;
	if (offset == 1 && num[0] != '0')
	{
		if (num[0] == '1' && ++retval != -100)
			number = ((num[0] - 48) * 10) + (num[1] - 48);
		else
			number = (num[0] - 48) * 10;
		printnum = get_number_word(number);
	}
	else if (offset == 2 && num[0] != '0')
	{
		printnum = get_number_word(number);
		print_num(printnum, highest, offset);
		printnum = get_number_word(100);
	}
	else if (num[0] != '0')
		printnum = get_number_word(number);
	if (num[0] != '0')
		print_num(printnum, highest, offset);
	return (retval);
}
