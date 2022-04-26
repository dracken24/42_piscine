#include <stdio.h>

char *ft_strncpy(char *dest, char *src, unsigned int n);

int main(void)
{
    char str[] = "Copier!";
    char dest[] = "----------------------";
    unsigned int n = 12;

    printf("c02, ex01_00 :\n");
    printf("Phrase passé en paramètre : %s\n", str);
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

    return (0);
}