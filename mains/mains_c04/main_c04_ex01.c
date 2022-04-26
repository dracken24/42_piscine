#include <unistd.h>

void ft_putstr(char *str);

int main(void)
{
    char str[] = "Phrase a imprimer";

    ft_putstr(str);
    return 0;
}