/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <nadesjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:04:54 by nadesjar          #+#    #+#             */
/*   Updated: 2022/03/15 13:32:38 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char *str);

int	main(int argc, char **argv)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
	if (argc == 3)
	{
		while (argv[2][i] != '\0')
		{
			if (argv[2][i] == argv[1][x])
			{
				x++;
				if (argv[1][x] == '\0')
				{
					write (1, "1", 1);
					return (0);
				}
			}
			i++;
			if (argv[2][i] == '\0')
				write(1, "0", 1);
		}
	}
	write (1, "\n", 1);
	return (0);
}
