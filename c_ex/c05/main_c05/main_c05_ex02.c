#include <stdio.h>

int ft_iterative_power(int nb, int power);

int main(void)
{
    int nb = 2;
    int power = 5;

    printf("retour attendu        : 64\n");
    printf("retour de la fonction : %d\n", ft_iterative_power(nb, power));
    return 0;
}