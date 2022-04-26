#include <stdio.h>

int ft_recursive_power(int nb, int power);

int main(void)
{
    int nb = 2;
    int power = 5;

    printf("retour attendu        : 32\n");
    printf("retour de la fonction : %d\n", ft_recursive_power(nb, power));
    return 0;
}