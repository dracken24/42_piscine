/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <nadesjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:35:55 by nadesjar          #+#    #+#             */
/*   Updated: 2022/03/15 17:06:28 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	ct_min;
	int	nbr;
	int	len;

	i = 0;
	ct_min = 1;
	nbr = 0;
	if (str[i] != '\0' && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			ct_min = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			nbr = (nbr * str_base) + (str[i] - 48);
		else if (str[i] >= 'a' && str[i] <= 'z')
			nbr = (nbr * str_base) + (str[i] - 97);
		else if (str[i] >= 'A' && str[i] <= 'Z')
			nbr = (nbr * str_base) + (str[i] - 65);
		else
			return (nbr * ct_min);
		i++;
	}
	return (0);
}
