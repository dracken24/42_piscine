#include <stdio.h>
#include <string.h>

char *ft_strstr(char *str, char *to_find);

int main()
{
	char	str[] = "abcdefghij";
    char    str2[] = "";
	char	to_find1[] = "defg";
	char	to_find2[] = "hij";
	char	to_find3[] = "ijk";
    char    to_find4[] = "";

	printf("\ntest1\nretour attendu : %s\nRetour fonction: %s\n", strstr(str, to_find1), ft_strstr(str, to_find1));
    printf("\ntest2\nretour attendu : %s\nRetour fonction: %s\n", strstr(str, to_find2), ft_strstr(str, to_find2));
    printf("\ntest3\nretour attendu : %s\nRetour fonction: %s\n", strstr(str, to_find3), ft_strstr(str, to_find3));
    printf("\ntest4\nretour attendu : %s\nRetour fonction: %s\n", strstr(str2, to_find3), ft_strstr(str2, to_find3));
    printf("\ntest5\nretour attendu : %s\nRetour fonction: %s\n", strstr(str, to_find4), ft_strstr(str, to_find4));
    printf("\ntest6\nretour attendu : %s\nRetour fonction: %s\n", strstr(str2, to_find4), ft_strstr(str2, to_find4));
}

