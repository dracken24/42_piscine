#include <stdio.h>
#include <string.h>
int ft_strncmp(char *s1, char *s2, unsigned int n);

int main()
{
    char s1[] = "Ceciestunemottreslong";
    char s2[] = "CeciesTunemottreslong";
    char s3[] = "Ceciestunemjttreslong";
    char s4[] = "";
    char s5[] = "Ceciestunemot treslong!";
    unsigned int x = 16;

    printf("\ntest1\nAttendu : %d\nFonction: %d", strncmp(s1, s1, x), ft_strncmp(s1, s1, x));
    printf("\ntest2\nAttendu : %d\nFonction: %d", strncmp(s1, s2, x), ft_strncmp(s1, s2, x));
    printf("\ntest3\nAttendu : %d\nFonction: %d", strncmp(s1, s3, x), ft_strncmp(s1, s3, x));
    printf("\ntest4\nAttendu : %d\nFonction: %d", strncmp(s1, s4, x), ft_strncmp(s1, s4, x));
    printf("\ntest5\nAttendu : %d\nFonction: %d", strncmp(s1, s5, x), ft_strncmp(s1, s5, x));
}
