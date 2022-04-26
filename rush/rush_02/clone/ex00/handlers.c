/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 23:46:18 by tparadis          #+#    #+#             */
/*   Updated: 2022/03/13 23:49:49 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*get_number_word(int nb)
{
	int	i;

	i = 0;
	while (g_dict[i])
	{
		if (i == 0 || g_dict[i - 1] == '\n')
		{
			if (read_num(&g_dict[i]) == nb)
			{
				while (g_dict[i] && g_dict[i] != ':')
					i++;
				return (&g_dict[i + 2]);
			}
		}
		i++;
	}
	return (NULL);
}

int	handle_stwenty(int i, char *num, int *highest)
{
	int	fi;

	fi = 0;
	if (num[i + fi] == '1')
	{
		print_num(get_number_word(10 + (num[i + 1 + fi] - 48)), *highest, 0);
		fi++;
	}
	else if (num[i] >= '2')
		print_num(get_number_word(*highest * (num[i + fi] - 48)), *highest, 0);
	fi++;
	*highest = get_num_length(get_full_num(&num[i + fi]));
	return (fi);
}

int	handle_normal(char *num, char *number, int *highest, int i)
{
	int	fi;

	fi = 0;
	if (num[i + fi] != '0')
		print_unit(num[i + fi], number, *highest);
	fi++;
	*highest = get_num_length(get_full_num(&num[i + fi]));
	return (fi);
}

int	handle_offset(char *num, int *highest, int i, char *number)
{
	int	offset;
	int	fi;

	fi = 0;
	offset = get_offset(get_full_num(&num[i + fi]));
	while (offset != -1)
	{
		if (print_offset(offset, &num[i + fi], *highest))
		{
			fi++;
			offset--;
		}
		fi++;
		offset--;
	}
	fi--;
	*highest = get_num_length(get_full_num(&num[i + fi]));
	number = get_number_word(*highest);
	if (num[i + fi] != '0' || num[i - 1 + fi] != '0' || num[i - 2 + fi] != '0')
		print_multiple(*highest);
	fi++;
	*highest = get_num_length(get_full_num(&num[i + fi]));
	return (fi);
}
