#include <stdio.h>
int ft_str_is_alpha(char *str);

int main(void)
{
    char str[] = "Ceciestbon";
    char str2[] = "Ceci n'est pas bon";
    char str3[] = "BAA444DDD56{[]}";
    char str4[] = "";

    printf("c02, ex03_00 :\n");
    printf("Phrase passé en paramètre : %s\n", str);
    printf("Retour attendu : 1\n");
    printf("Votre retour   : %d\n", ft_str_is_alpha(str));

/******************************************************************************/

    printf("c02, ex03_01 :\n");
    printf("Phrase passé en paramètre : %s\n", str2);
    printf("Retour attendu : 0\n");
    printf("Votre retour   : %d\n", ft_str_is_alpha(str2));

/******************************************************************************/

    printf("c02, ex03_02 :\n");
    printf("Phrase passé en paramètre : %s\n", str3);
    printf("Retour attendu : 0\n");
    printf("Votre retour   : %d\n", ft_str_is_alpha(str3));

/******************************************************************************/

    printf("c02, ex03_03 :\n");
    printf("Phrase passé en paramètre : %s\n", str4);
    printf("Retour attendu : 1\n");
    printf("Votre retour   : %d\n", ft_str_is_alpha(str4));

    return (0);
}