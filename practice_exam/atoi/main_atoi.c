#include <stdio.h>
#include <stdlib.h>

int ft_atoi(const char *str);

int main(void)
{
	char str[] = "--+--3356jjd7 ";
	char str1[] = "      +45549jjd7 ";
	char str2[] = "      -6-+--3356jjd7 ";
	char str3[] = "";

	printf("str passé a atoi  :%s\n", str);
	printf("retour attendu    :0\n");
	printf("retour fonction   :%d\n", ft_atoi(str));
	printf("atoi de base      :%d\n\n", atoi(str));

	/**********************************************************************/

	printf("\nstr passé a atoi  :%s\n", str1);
	printf("retour attendu    :45549\n");
	printf("retour fonction   :%d\n", ft_atoi(str1));
	printf("atoi de base      :%d\n\n", atoi(str1));

	/**********************************************************************/

	printf("\nstr passé a atoi  :%s\n", str2);
	printf("retour attendu    :-6\n");
	printf("retour fonction   :%d\n", ft_atoi(str2));
	printf("atoi de base      :%d\n\n", atoi(str2));

	/**********************************************************************/

	printf("\nstr passé a atoi  :%s\n", str3);
	printf("retour attendu    :0\n");
	printf("retour fonction   :%d\n", ft_atoi(str3));
	printf("atoi de base      :%d\n\n", atoi(str3));

	/**********************************************************************/
}