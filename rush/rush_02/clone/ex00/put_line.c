/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 23:45:49 by tparadis          #+#    #+#             */
/*   Updated: 2022/03/13 23:45:53 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	validate_line(char *line)
{
	int				i;
	long long int	num;
	int				printable;
	int				column;

	i = 0;
	num = read_num(line);
	column = -1;
	printable = -1;
	if (num == -1 || !does_contain(num))
		return (-1);
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == ':')
			column = 1;
		if (column == 1 && line[i] <= 126 && line[i] >= 33)
			printable = 1;
		i++;
	}
	if (column == -1 || printable == -1)
	{
		return (-1);
	}
	return (1);
}

int	put_line_two(char *line, int count, int i, char *buff)
{
	int	printable;

	printable = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == ':')
		{
			buff[count] = line[i];
			buff[count + 1] = ' ';
			i++;
			count += 2;
			break ;
		}
		i++;
	}
	while (line[i++] != 0 && line[i] != '\n')
	{
		if ((line[i] >= 33 && line[i] <= 126)
			|| (printable && line[i] >= 32 && line[i] <= 126))
		{
			buff[count++] = line[i];
			printable = 1;
		}
	}
	return (count);
}

int	put_line(char *line, char *buff)
{
	int	i;
	int	count;
	int	column;

	i = -1;
	count = 0;
	column = 0;
	if (validate_line(line) == -1)
		return (0);
	while (line[++i] && line[i] != '\n' && is_numeric(line[i]))
		buff[count++] = line[i];
	count = put_line_two(line, count, i, buff);
	buff[count] = '\n';
	return (count + 1);
}
