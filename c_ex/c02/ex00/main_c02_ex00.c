#include <stdio.h>
#include <string.h>
char *ft_strcpy(char *dest, char *src);

int main(void)
{
    char str[] = "Copier cette phrase!!?";
    char dest[] = "-----------------------------";

    
    printf("c02, ex00 :\n");
    printf("Phrase passé en paramètre: %s\n", str);

    ft_strcpy(dest, str);

    printf("Phrase copié dans *dest  : %s\n", dest);

    return (0);
}