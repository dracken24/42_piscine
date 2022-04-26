/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <nadesjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:10:07 by nadesjar          #+#    #+#             */
/*   Updated: 2022/03/14 12:46:42 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

int	*ft_range(int min, int max)
{
	int	*diff;
	int	i;

	if (min >= max)
		return (NULL);
	diff = malloc(sizeof(int) * (max - min));
	i = 0;
	while (i < (max - min))
	{
		diff[i] = min + i;
		i++;
	}
	return (diff);
}
