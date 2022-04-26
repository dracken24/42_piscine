#include <stdio.h>
int ft_str_is_uppercase(char *str);

int main(void)
{
    char str[] = "CeciNestPasBon";
    char str2[] = "BAA444DDD56{[]}";
    char str3[] = "CECIESTBON";
    char str4[] = "";

    printf("c02, ex05_00 :\n");
    printf("Phrase passé en paramètre : %s\n", str);
    printf("Retour attendu : 0\n");
    printf("Votre retour   : %d\n", ft_str_is_uppercase(str));

    /******************************************************************************/

    printf("c02, ex05_01 :\n");
    printf("Phrase passé en paramètre : %s\n", str2);
    printf("Retour attendu : 0\n");
    printf("Votre retour   : %d\n", ft_str_is_uppercase(str2));

    /******************************************************************************/

    printf("c02, ex05_02 :\n");
    printf("Phrase passé en paramètre : %s\n", str3);
    printf("Retour attendu : 1\n");
    printf("Votre retour   : %d\n", ft_str_is_uppercase(str3));

    /******************************************************************************/

    printf("c02, ex05_03 :\n");
    printf("Phrase passé en paramètre : %s\n", str4);
    printf("Retour attendu : 1\n");
    printf("Votre retour   : %d\n", ft_str_is_uppercase(str4));

    return (0);
}