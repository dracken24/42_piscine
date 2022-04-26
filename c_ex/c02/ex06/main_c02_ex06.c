#include <stdio.h>
int ft_str_is_printable(char *str);

int main(void)
{
    char str[] = "Ceci est Bon!!    ?";
    char str2[] = "BOOO444NNN 56{[  ]}";
    char str3[] = "Cecies\n 3tunephrase2";
    char str4[] = "";

    printf("c02, ex06_00 :\n");
    printf("Phrase passé en paramètre : %s\n", str);
    printf("Retour attendu : 1\n");
    printf("Votre retour   : %d\n", ft_str_is_printable(str));

    /******************************************************************************/

    printf("c02, ex06_01 :\n");
    printf("Phrase passé en paramètre : %s\n", str2);
    printf("Retour attendu : 1\n");
    printf("Votre retour   : %d\n", ft_str_is_printable(str2));

    /******************************************************************************/

    printf("c02, ex06_02 :\n");
    printf("Phrase passé en paramètre : %s\n", str3);
    printf("Retour attendu : 0\n");
    printf("Votre retour   : %d\n", ft_str_is_printable(str3));

    /******************************************************************************/

    printf("c02, ex06_03 :\n");
    printf("Phrase passé en paramètre : %s\n", str4);
    printf("Retour attendu : 1\n");
    printf("Votre retour   : %d\n", ft_str_is_printable(str4));

    return (0);
}