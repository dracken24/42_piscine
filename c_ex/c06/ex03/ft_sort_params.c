/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:07:07 by nadesjar          #+#    #+#             */
/*   Updated: 2022/03/25 11:30:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2);
void	ft_swap(char **argv, int min, int max);
void	ft_putstr(char *str);

int	main(int argc, char **argv)
{
	int	min;
	int	max;

	min = 1;
	while (min < argc)
	{
		max = min + 1;
		while (max <= argc - 1)
		{
			if (ft_strcmp(argv[min], argv[max]) > 0)
				ft_swap(argv, min, max);
			max++;
		}
		min++;
	}
	min = 1;
	while (min < argc)
	{
		ft_putstr(argv[min]);
		min++;
	}
	return (0);
}

void	ft_swap(char **argv, int min, int max)
{
	char	*temp;

	temp = argv[min];
	argv[min] = argv[max];
	argv[max] = temp;
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write (1, "\n", 1);
}

