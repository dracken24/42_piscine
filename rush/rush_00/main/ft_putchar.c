#include <unistd.h>

void ft_putchar(char x)
{
    write(1, &x, 1);
}