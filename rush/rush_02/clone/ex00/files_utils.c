/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 23:46:46 by tparadis          #+#    #+#             */
/*   Updated: 2022/03/13 23:49:33 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "rush02.h"

int	get_file_size(int fildes)
{
	int		readsz;
	char	tempbuf[128];
	int		total;

	readsz = -1;
	total = 0;
	while (readsz != 0)
	{
		readsz = read(fildes, tempbuf, 128);
		total += readsz;
	}
	return (total);
}

int	reset_file(char *file, int fildes)
{
	close(fildes);
	return (open(file, O_RDONLY));
}

char	*get_dict(int size, int fildes)
{
	char	*dict;
	int		i;
	char	*temp;
	int		count;

	temp = malloc(size + 1);
	dict = malloc(size + 1);
	read(fildes, temp, size);
	temp[size] = 0;
	i = 0;
	count = 0;
	while (temp[i])
	{
		if (i == 0 || temp[i - 1] == '\n')
		{
			count += put_line(&temp[i], &dict[count]);
		}
		i++;
	}
	free(temp);
	return (dict);
}
