/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <nadesjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:31:53 by nadesjar          #+#    #+#             */
/*   Updated: 2022/02/28 13:31:53 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	putminus(char str[])
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		if (str[x] >= 'A' && str[x] <= 'Z')
			str[x] += 32;
		x++;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	x;
	int	a;

	a = 1;
	x = 0;
	putminus(str);
	x = 0;
	while (str[x] != '\0')
	{
		if (str[x] >= 'a' && str[x] <= 'z')
		{
			if (a == 1)
				str[x] -= 32;
			a = 0;
		}
		else if (str[x] >= '0' && str[x] <= '9')
			a = 0;
		else
			a = 1;
		x++;
	}
	return (str);
}
