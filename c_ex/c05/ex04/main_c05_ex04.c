#include <stdio.h>

int ft_fibonacci(int index);

int main(void)
{
    int index = 11;

    printf("Retour attendu       : 89\n");
    printf("Retour de la fonction: %d\n", ft_fibonacci(index));
    return 0;
}
