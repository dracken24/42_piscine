#include <stdio.h>
int ft_str_is_lowercase(char *str);

int main(void)
{
    char str[] = "CeciNestPasBon";
    char str2[] = "BAA444DDD56{[]}";
    char str3[] = "ceciestbon";
    char str4[] = "";

    printf("c02, ex04_00 :\n");
    printf("Phrase passé en paramètre : %s\n", str);
    printf("Retour attendu : 0\n");
    printf("Votre retour   : %d\n", ft_str_is_lowercase(str));

    /******************************************************************************/

    printf("c02, ex04_01 :\n");
    printf("Phrase passé en paramètre : %s\n", str2);
    printf("Retour attendu : 0\n");
    printf("Votre retour   : %d\n", ft_str_is_lowercase(str2));

    /******************************************************************************/

    printf("c02, ex04_02 :\n");
    printf("Phrase passé en paramètre : %s\n", str3);
    printf("Retour attendu : 1\n");
    printf("Votre retour   : %d\n", ft_str_is_lowercase(str3));

    /******************************************************************************/

    printf("c02, ex04_03 :\n");
    printf("Phrase passé en paramètre : %s\n", str4);
    printf("Retour attendu : 1\n");
    printf("Votre retour   : %d\n", ft_str_is_lowercase(str4));

    return (0);
}