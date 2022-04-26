#include <stdio.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);

int main(void)
{
	char str[] = "Copier cette phrase!!?";
	char dest[] = "kjkjsdfhkhhkhjkghufunkukrfkhrghrjghhkr";
	int len;

	printf("\nStr  : %s\n", str);
	printf("dest : %s\n", dest);
	printf("size : 11\n\n");

	len = ft_strlcpy(dest, str, 11);

	printf("Source      : %s\nDestination : %s\nlen         : %d\n", str, dest, len);
}