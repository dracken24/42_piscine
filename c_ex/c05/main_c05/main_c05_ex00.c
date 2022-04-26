#include <stdio.h>

int ft_iterative_factorial(int nb);

int main(void)
{
    int nb = 6;

    printf("Retour attendu        : 720\n");
    printf("Retour de la fonction : %d\n", ft_iterative_factorial(nb));
    return (0);
}