/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <nadesjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:31:26 by nadesjar          #+#    #+#             */
/*   Updated: 2022/03/07 17:31:26 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	count;

	count = 1;
	if (nb == 0)
		return (0);
	while (count * count <= nb)
	{
		if (count * count == nb)
			return (count);
		else if (count >= 46341)
			return (0);
		count++;
	}
	return (0);
}
