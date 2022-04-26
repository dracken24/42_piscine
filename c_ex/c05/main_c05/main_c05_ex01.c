#include <stdio.h>

int ft_recursive_factorial(int nb);

	int main(void)
{
	int	nb = 6;

	printf("Retour attendu        : 720\n");
	printf("Retour de la fonction : %d\n", ft_recursive_factorial(nb));
	return (0);
}