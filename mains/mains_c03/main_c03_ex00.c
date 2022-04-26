#include <stdio.h>
#include <string.h>
int ft_strcmp(char *s1, char *s2);

int main()
{
    char s1[] = "bonjour";
    char s2[] = "bonzour";
    char s3[] = "bonbour";
    char s4[] = "bonjou";
    char s5[] = "Bonjour!";

    printf("\ntest1\nAttendu : %d\nFonction: %d", strcmp(s1, s1), ft_strcmp(s1, s1));
    printf("\ntest2\nAttendu : %d\nFonction: %d", strcmp(s1, s2), ft_strcmp(s1, s2));
    printf("\ntest3\nAttendu : %d\nFonction: %d", strcmp(s1, s3), ft_strcmp(s1, s3));
    printf("\ntest4\nAttendu : %d\nFonction: %d", strcmp(s1, s4), ft_strcmp(s1, s4));
    printf("\ntest5\nAttendu : %d\nFonction: %d", strcmp(s1, s5), ft_strcmp(s1, s5));
}
