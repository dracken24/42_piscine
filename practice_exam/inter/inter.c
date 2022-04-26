/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <nadesjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:37:39 by nadesjar          #+#    #+#             */
/*   Updated: 2022/03/10 17:32:14 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_check(char i, char *str);
void ft_putchar(char c);

int main(int argc, char **argv)
{
    int i;
    int j;
    char str[256];

    i = 0;
    j = 0;
    if (argc == 3)
    {
        while (argv[2][i] != '\0')
        {
            if (argv[2][i] == argv[1][j])
            {
                ft_check(argv[1][j], str);
                j++;
            }
            i++;
        }
    }
    ft_putchar('\n');
    return (0);
}

int ft_check(char i, char *str)
{
    int x;

    x = 0;
    while (str[x] != i)
    {
        if (str[x] == '\0')
        {
            ft_putchar(i);
            str[x] = i;
            return (0);
        }
        x++;
    }
    return (0);
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}