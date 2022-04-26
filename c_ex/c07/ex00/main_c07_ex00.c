#include <stdio.h>
#include <string.h>

char *ft_strdup(char *src);

    int main(void)
{
    char str[] = "Copier cette phrase !!?";

    printf("Phrase de depart : Copier cette phrase !!?\n\n");
    printf("retour attendu   :%s\n", strdup(str));
    printf("Votre retour     :%s\n", ft_strdup(str));
    return 0;
}