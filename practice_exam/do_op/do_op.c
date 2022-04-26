/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <nadesjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:27:05 by nadesjar          #+#    #+#             */
/*   Updated: 2022/03/12 16:03:55 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	res;
	int	one;
	int	two;
	int	middle;

	middle = argv[2][0];
	one = atoi(argv[1]);
	two = atoi(argv[3]);
	res = 0;
	if (argc == 4)
	{
		if (middle == '+')
			res = one + two;
		if (middle == '-')
			res = one - two;
		if (middle == '*')
			res = one * two;
		if (middle == '/')
			res = one / two;
		if (middle == '%')
			res = one % two;
	}
	printf("%d\n", res);
	return (0);
}
