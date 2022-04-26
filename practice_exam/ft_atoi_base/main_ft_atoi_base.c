#include <stdio.h>
#include <stdlib.h>

int ft_atoi_base(const char *str, int str_base);

int main(void)
{
	char str[] = "--+--33bh56jjd7 ";
	char str1[] = "45a54bf9j4jd7 ";
	char str2[] = "-ab446kdf-+++--3356jjd7 ";
	char str3[] = "";
	int	*base = "0123456789abcdef";

	printf("str passé a atoi  :%s\n", str);
	printf("retour attendu    :0\n");
	printf("retour fonction   :%d\n", ft_atoi_base(str, *base));

	/**********************************************************************/

	printf("\nstr passé a atoi  :%s\n", str1);
	printf("retour attendu    :45a54bf9\n");
	printf("retour fonction   :%d\n", ft_atoi_base(str1, *base));

	/**********************************************************************/

	printf("\nstr passé a atoi  :%s\n", str2);
	printf("retour attendu    :-ab446\n");
	printf("retour fonction   :%d\n", ft_atoi_base(str2, *base));

	/**********************************************************************/

	printf("\nstr passé a atoi  :%s\n", str3);
	printf("retour attendu    :0\n");
	printf("retour fonction   :%d\n", ft_atoi_base(str3, *base));

	/**********************************************************************/
}