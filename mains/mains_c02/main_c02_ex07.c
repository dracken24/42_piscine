#include <stdio.h>
char *ft_strupcase(char *str);

int main(void)
{
    char str[] = "Ceci est Bon!!?";
    char str2[] = "bOoO444Nsdd 56{[]}";
    char str3[] = "Cecies 3tunephrase2";
    char str4[] = "";

    printf("c02, ex07_00 :\n");
    printf("Valeur d'entree : %s\n", str);
    printf("Votre retour    : %s\n", ft_strupcase(str));

    /******************************************************************************/

    printf("c02, ex07_01 :\n");
    printf("Valeur d'entree : %s\n", str2);
    printf("Votre retour    : %s\n", ft_strupcase(str2));

    /******************************************************************************/

    printf("c02, ex07_02 :\n");
    printf("Valeur d'entree : %s\n", str3);
    printf("Votre retour    : %s\n", ft_strupcase(str3));

    /******************************************************************************/

    printf("c02, ex07_03 :\n");
    printf("Valeur d'entree : %s\n", str4);
    printf("Votre retour    : %s\n", ft_strupcase(str4));

    return (0);
}