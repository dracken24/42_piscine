#include <stdio.h>
char *ft_strcapitalize(char *str);

    int main(void)
{
    char str[] = "meTTre La pReMierE LettRe EN maJUscuLE!!?";
    char str2[] = "bOoO44 4Nsdd 56{[]}";
    char str3[] = "Cecies 3tun ePHraSE2";
    char str4[] = "";

    printf("c02, ex07_00 :\n");
    printf("Valeur d'entree : %s\n", str);
    printf("Votre retour    : %s\n", ft_strcapitalize(str));

    /******************************************************************************/

    printf("c02, ex07_01 :\n");
    printf("Valeur d'entree : %s\n", str2);
    printf("Votre retour    : %s\n", ft_strcapitalize(str2));

    /******************************************************************************/

    printf("c02, ex07_02 :\n");
    printf("Valeur d'entree : %s\n", str3);
    printf("Votre retour    : %s\n", ft_strcapitalize(str3));

    /******************************************************************************/

    printf("c02, ex07_03 :\n");
    printf("Valeur d'entree : %s\n", str4);
    printf("Votre retour    : %s\n", ft_strcapitalize(str4));

    return (0);
}