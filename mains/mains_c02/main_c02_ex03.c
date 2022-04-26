#include <stdio.h>
int ft_str_is_numeric(char *str);

int main(void)
{
    char str[] = "Ceci n'est pas bon";
    char str2[] = "BAA444DDD56{[]}";
    char str3[] = "7736652";
    char str4[] = "";

    printf("c02, ex02_00 :\n");
    printf("Phrase passé en paramètre : %s\n", str);
    printf("Retour attendu : 0\n");
    printf("Votre retour   : %d\n", ft_str_is_numeric(str));

    /******************************************************************************/

    printf("c02, ex02_01 :\n");
    printf("Phrase passé en paramètre : %s\n", str2);
    printf("Retour attendu : 0\n");
    printf("Votre retour   : %d\n", ft_str_is_numeric(str2));

    /******************************************************************************/

    printf("c02, ex02_02 :\n");
    printf("Phrase passé en paramètre : %s\n", str3);
    printf("Retour attendu : 1\n");
    printf("Votre retour   : %d\n", ft_str_is_numeric(str3));

    /******************************************************************************/

    printf("c02, ex02_03 :\n");
    printf("Phrase passé en paramètre : %s\n", str4);
    printf("Retour attendu : 1\n");
    printf("Votre retour   : %d\n", ft_str_is_numeric(str4));

    return (0);
}