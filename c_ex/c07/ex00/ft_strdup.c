/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <nadesjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:34:41 by nadesjar          #+#    #+#             */
/*   Updated: 2022/03/15 12:52:01 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}

char	*ft_strdup(char *src)
{
	char	*cpstr;
	int		strln;
	int		i;

	i = 0;
	strln = ft_strlen(src);
	cpstr = malloc(sizeof(char) * (strln + 1));
	if (!cpstr)
		return (NULL);
	while (src[i] != '\0')
	{
		cpstr[i] = src[i];
		i++;
	}
	cpstr[i] = '\0';
	return (cpstr);
}
