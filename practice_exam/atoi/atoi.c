int ft_atoi(const char *str)
{
    int i;
    int ctmin;
    int numb;

    i = 0;
    ctmin = 1;
    numb = 0;
    while (str[i] && str[i] <= 32)
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            ctmin *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9' && str[i])
    {
        numb = (str[i++] - 48) + (numb * 10);
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (numb * ctmin);
    }
    return (0);
}