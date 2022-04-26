/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <nadesjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:09:30 by nadesjar          #+#    #+#             */
/*   Updated: 2022/03/02 11:48:47 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	ctmin;
	int	numb;

	i = 0;
	ctmin = 1;
	numb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i++] == 45)
			ctmin *= -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		numb = (str[i++] - 48) + (numb * 10);
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (numb * ctmin);
	}
	return (0);
}
