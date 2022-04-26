/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 20:12:52 by marvin            #+#    #+#             */
/*   Updated: 2022/02/16 20:12:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    int x;

    x = 0;
    if (argc != 2)
    {
        ft_putchar('\n');
        return (0);
    }

    while (argv[1][x] != '\0')
    {
        if (argv[1][x] >= 'a' && argv[1][x] <= 'z')
            argv[1][x] = 'a' - (argv[1][x] - 'z');
        
        else if (argv[1][x] >= 'A' && argv[1][x] <= 'Z')
            argv[1][x] = 'A' - (argv[1][x] - 'Z');

        ft_putchar(argv[1][x]);
        x++;
    }
    ft_putchar('\n');
    return (0);
}