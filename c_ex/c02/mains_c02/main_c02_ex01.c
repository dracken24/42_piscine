#include <stdio.h>

char *ft_strncpy(char *dest, char *src, unsigned int n);

int main(void)
{
    char str[] = "Copier!";
    char dest[] = "----------------------";
    unsigned int n = 12;

    printf("c02, ex01_00 :\n");
    printf("Phrase passé en paramètre : %s", str);
    printf("Phrase initiale dans *dest: %s\n", dest);

    ft_strncpy(dest, str, n);

    printf("Phrase copié dans *dest   : %s\n", dest);

    /******************************************************/

    char str1[] = "Copier cette phrase!!?";
    char dest1[] = "----------------------";
    unsigned int n1 = 12;

    printf("c02, ex01_01 :\n");
    printf("Phrase passé en paramètre : %s\n", str1);
    printf("Phrase initiale dans *dest: %s\n", dest1);

    ft_strncpy(dest1, str1, n1);

    printf("Phrase copié dans *dest   : %s\n", dest1);

    /******************************************************/

    char str2[] = "Copier cette phrase!!?";
    char dest2[] = "-------";
    unsigned int n2 = 12;

    printf("c02, ex01_02 :\n");
    printf("Phrase passé en paramètre : %s\n", str2);
    printf("Phrase initiale dans *dest: %s\n", dest2);

    ft_strncpy(dest2, str2, n2);

    printf("Phrase copié dans *dest   : %s\n", dest2);
    return (0);
}