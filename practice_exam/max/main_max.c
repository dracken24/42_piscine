#include <stdio.h>

int max(int *tab, unsigned int len);

int main(void)
{
    int tab[] = { 66, 89, 355, 74, 76, 242};

    printf("%d\n", max(tab, 6));
    return 0;
}
