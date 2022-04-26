
void ft_swap(int *tab, int min, int max);

int max(int *tab, unsigned int len)
{
	int	min;
	int	max;

	min = 0;
	if (len == 0)
		return (0);
	while (min < len)
	{
		max = min + 1;
		while (max < len)
		{
			if (tab[min] < tab[max])
				ft_swap(tab, min, max);
			max++;
		}
		min++;
	}
	return (tab[len - 1]);
}

void	ft_swap(int *tab, int min, int max)
{
	int	temp;

	temp = tab[min];
	tab[min] = tab[max];
	tab[max] = temp;
}