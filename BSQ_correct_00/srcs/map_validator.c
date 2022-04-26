/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 22:44:54 by iamongeo          #+#    #+#             */
/*   Updated: 2022/03/16 23:28:03 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "file_data.h"

int	print_map_error(void);

static t_file_data	*g_fdata;
static char			*g_buff;
static int			g_rem;

int	is_valid_map_char(char c)
{
	return (c == g_fdata->empty || c == g_fdata->obst || c == g_fdata->full);
}

int	copy_map(int bsize, int boff, int row, int col)
{
	if (row == g_fdata->height)
		return (boff);
	if ((g_fdata->width - col) < (bsize - boff))
		g_rem = g_fdata->width - col;
	else
		g_rem = bsize - boff;
	while (g_rem-- && is_valid_map_char(g_buff[boff]))
		g_fdata->map[row][col++] = g_buff[boff++];
	if (g_rem != -1)
		return (print_map_error());
	if (boff == bsize)
	{
		bsize = read(g_fdata->fdesc, g_buff, RBUFF_SIZE);
		if (!bsize)
			return (print_map_error());
		return (copy_map(bsize, 0, row, col));
	}
	else
	{
		if (g_buff[boff] != '\n')
			return (print_map_error());
		return (copy_map(bsize, boff + 1, row + 1, 0));
	}
}

void	free_map(t_file_data *fdata)
{
	int	i;

	i = -1;
	while (++i < fdata->height)
		free(fdata->map[i]);
	free(fdata->map);
}

char	**map_malloc(int height, int width)
{
	int		i;
	char	**map;

	map = malloc(sizeof(char *) * height);
	if (!map)
		return (0);
	i = -1;
	while (++i < height)
	{
		map[i] = malloc(sizeof(char) * (width + 1));
		if (!map[i])
			return (0);
		map[i][width] = '\0';
	}
	return (map);
}

int	validate_map(t_file_data *f_data, char *buff, int header_offset, int size)
{
	int		i;
	char	**map;

	g_fdata = f_data;
	g_buff = buff;
	g_rem = 0;
	i = 0;
	while (g_buff[header_offset + i] && g_buff[header_offset + i] != '\n')
		i++;
	g_fdata->width = i;
	if (g_fdata->width == 0 || g_fdata->height == 0)
		return (0);
	map = map_malloc(g_fdata->height, g_fdata->width);
	if (!map)
	{
		print_map_error();
		return (0);
	}
	g_fdata->map = map;
	if (copy_map(size, header_offset, 0, 0) == -1)
		return (0);
	return (1);
}
