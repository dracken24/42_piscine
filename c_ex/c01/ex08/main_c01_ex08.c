
#include <stdio.h>

void ft_sort_int_tab(int *tab, int size);

int main(void)
{
	int tab[] = { 4, 13, 26, 33, 45, 42, 24, 1};
	int	i = 0;

	ft_sort_int_tab(tab, 8);
	while (tab[i] < 8)
	{
		printf("%d\n", tab[i]);
		i++;
	}
	return 0;
}
