/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 11:22:26 by nadesjar          #+#    #+#             */
/*   Updated: 2022/03/19 18:24:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (dest[x] != '\0')
		x++;
	while (src[y] != '\0')
		dest[x++] = src[y++];
	dest[x] = '\0';
	return (dest);
}

char	*ft_transfert(int size, char **strs, char *sep, char *allstr)
{
	int	i;

	i = 0;
	while (i < size)
	{
		allstr = ft_strcat(allstr, strs[i]);
		if (i < size - 1)
			allstr = ft_strcat(allstr, sep);
		i++;
	}
	return (allstr);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		ct_str;
	int		ct_sep;
	char	*allstr;

	i = 0;
	if (size <= 0)
	{
		allstr = malloc(sizeof(char));
		return (allstr);
	}
	while (i < size)
		ct_str = ft_strlen(strs[i++]) + ct_str;
	ct_sep = ft_strlen(sep) * (size - 1);
	allstr = malloc(sizeof(char) * (ct_str + ct_sep));
	if (!allstr)
		return (NULL);
	allstr = ft_transfert(size, strs, sep, allstr);
	return (allstr);
}
