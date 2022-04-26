#include <stdio.h>
#include <string.h>

unsigned int ft_strlcat(char *dest, char *src, unsigned int size);

int main(void)
{
    char dest[100] = "Bonjour qui:";
    char dest2[100] = "";
    char src[] = "Chuck Noris is the best!!!";

    printf("\nPhrase passé en paramètre: %s\n\n", src);
    printf("Retour attendu : %d\nRetour fonction: %d\n", strlcat(dest, src, 11), ft_strlcat(dest, src, 11));
    printf("\nPhrase passé en paramètre: %s\n\n", src);
    printf("Retour attendu : %d\nRetour fonction: %d\n", strlcat(dest2, src, 11), ft_strlcat(dest2, src, 11));
    return 0;
}
