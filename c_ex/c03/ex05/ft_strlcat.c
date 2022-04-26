int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int k;
	int len;

	i = 0;
	len = ft_strlen(src);
	while (dest[i] != '\0')
		i++;
	k = 0;
	while (src[k] != '\0' && k < size)
	{
		dest[i] = src[k];
		i++;
		k++;
	}
	dest[i] = '\0';
	return (len);
}
