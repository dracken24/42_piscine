/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_c04_ex00.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <nadesjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:59:06 by nadesjar          #+#    #+#             */
/*   Updated: 2022/03/02 10:59:06 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str);

int	main(void)
{
	char	*str;

	str = "Copier cette phrase";
	ft_strlen(str);
	printf("\nPhrase a copier : %s\n", str);
	printf("Retour attendu : %ld\n", strlen(str));
	printf("Votre retour   : %d\n", ft_strlen(str));
	return (0);
}
