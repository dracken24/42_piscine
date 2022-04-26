#include <string.h>
#include <stdio.h>

int *ft_range(int min, int max);

int main(void)
{
    int min = 12;
    int max = 24;

    ft_range(min, max);
    printf("Min dans main: %d  Max dans main: %d\n", min, max);
    
    printf("Retour de la fonction: %d\n", ft_range(min, max));

    return 0;
}