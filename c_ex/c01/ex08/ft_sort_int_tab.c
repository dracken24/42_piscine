
void    ft_sort_int_tab(int *tab, int size)
{
    int i;
    int k;
    int temp;

    i = 0;
    while (i < size)
    {
        k = i + 1;
        while (k < size)
        {
            if (tab[i] > tab[k])
            {
                temp = tab[i];
                tab[i] = tab[k];
                tab[k] = temp;
            }
            k++;
        }
        i++;
    }
}
