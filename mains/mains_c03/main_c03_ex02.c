#include <stdio.h>
#include <string.h>
char *ft_strcat(char *dest, char *src);

int main()
{
    char dest[100] = "Bonjour qui:----------------";
    char dest2[100] = "Bonjour qui:----------------";
    char src[] = " a toi!";

    dest[12] = '\0';
    dest2[12] = '\0';
    printf("Retour attendu : %s\nRetour fonction: %s", strcat(dest2, src), ft_strcat(dest, src));
}
