#include <stdio.h>
#include <string.h>
char *ft_strstr(char *str, char *to_find);

int main()
{
    char str1[] = "Est ce que Chuck Noris est present?";
    char str2[] = "Non, C h u c k n'est pas present";
    char src[] = "Chuck";



    printf("\nPhrase passé en paramètre: %s\n\n", str1);
    printf("Retour attendu : %s\nRetour fonction: %s\n", strstr(str1, src), ft_strstr(str1, src));
    printf("\n");
    printf("\nPhrase passé en paramètre: %s\n\n", str2);
    printf("Retour attendu : %s\nRetour fonction: %s\n", strstr(str2, src), ft_strstr(str2, src));
}