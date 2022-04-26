/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:37:58 by nadesjar          #+#    #+#             */
/*   Updated: 2022/03/19 20:13:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	x;
	int	y;

	x = 0;
	if(to_find[x] == '\0')
		return (str);
	while (str[x++] != '\0')
	{
		y = 0;
		while (to_find[y] == str[x])
		{
			y++;
			x++;
			if (to_find[y] == '\0')
			{
				while (y-- != 0)
					x--;
				return (str + x);
			}
		}
	}
	return (0);
}
