#include <stdio.h>
#include <string.h>
char *ft_strncat(char *dest, char *src, unsigned int nb);

int main()
{
    char dest[100] = "Bonjour qui:----------------";
    char dest2[100] = "Bonjour qui:----------------";
    char src[] = "Chuck Noris is the best!!!";
    int nb = 11;

    dest[12] = '\0';
    dest2[12] = '\0';
    printf("\nPhrase passé en paramètre: %s\n\n", src);
    printf("Retour attendu : %s\nRetour fonction: %s\n", strncat(dest2, src, nb), ft_strncat(dest, src, nb));
}