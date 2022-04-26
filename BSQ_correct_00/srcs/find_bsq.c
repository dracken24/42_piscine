/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bsq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:20:53 by iamongeo          #+#    #+#             */
/*   Updated: 2022/03/16 23:14:44 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "file_data.h"

static char			g_em;
static char			g_ob;
static char			g_fu;
static t_file_data	*g_fdata;
static char			**g_map;
static int			g_coli_occured;
static int			g_coli_x;
static int			g_x;
static int			g_y;
static int			g_edge;

int	is_valid_field(int x, int y, int side)
{
	int	i;
	int	j;

	if ((x + side) > g_fdata->width || (y + side) > g_fdata->height)
		return (0);
	i = -1;
	while (++i < side)
	{
		j = -1;
		while (++j < side)
		{
			if (g_map[y + i][x + j] == g_ob)
			{
				g_coli_x = x + j;
				g_coli_occured = 1;
				return (0);
			}
		}
	}
	return (1);
}

void	init_static_vars(t_file_data *fdata)
{
	g_ob = fdata->obst;
	g_em = fdata->empty;
	g_fu = fdata->full;
	g_fdata = fdata;
	g_map = fdata->map;
	g_x = 0;
	g_y = 0;
	g_edge = 0;
}

void	print_bsq(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_y)
	{
		write(1, g_map[i++], g_fdata->width);
		write(1, "\n", 1);
	}
	while (i < (g_y + g_edge))
	{
		write(1, g_map[i], g_x);
		j = -1;
		while (++j < g_edge)
			write(1, &g_fu, 1);
		write(1, g_map[i++] + g_x + g_edge, g_fdata->width - (g_x + g_edge));
		write(1, "\n", 1);
	}
	while (i < g_fdata->height)
	{
		write(1, g_map[i++], g_fdata->width);
		write(1, "\n", 1);
	}
}

int	find_bsq(t_file_data *fdata)
{
	int	i;
	int	j;

	init_static_vars(fdata);
	i = -1;
	while (++i < (g_fdata->height - g_edge))
	{
		j = -1;
		while (++j < (g_fdata->width - g_edge))
		{
			g_coli_occured = 0;
			while (is_valid_field(j, i, g_edge + 1))
			{
				g_edge++;
				g_x = j;
				g_y = i;
			}
			j += g_coli_occured * (g_coli_x - j);
			if (j >= (g_fdata->width - g_edge))
				break ;
		}
	}
	print_bsq();
	return (0);
}
