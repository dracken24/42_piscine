/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 08:23:23 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/03/19 18:18:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max);

int	main()
{
	int		*range;
	int		i;
    int min = 13;
    int max = 24;
    
	i = 0;
	printf("Min: %d, Max: %d, return : %d\n", min, max, ft_ultimate_range(&range, min, max));
	while (i < (max - min))
	{
	    printf("> %d\n", range[i]);
		i++;
	}
	return (0);
}
