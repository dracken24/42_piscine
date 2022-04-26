#include <stdio.h>

int ft_is_prime(int nb);

int main(void)
{
    int nb = 97;

    printf("Retour attendu        : 1\n");
    printf("Retour de la fonction : %d\n", ft_is_prime(nb));
    return 0;
}