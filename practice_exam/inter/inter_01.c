#include <unistd.h>

int ft_check(char letter, char *str, int ct);

int main(int argc, char **argv)
{
	int i = 0;
	int k = 0;

	if (argc != 3)
		return (0);
	if (argc == 3)
	{
		while (argv[2][i] != '\0')
		{
			if (argv[2][i] == argv[1][k] && argv[1][k] != '\0')
			{
				ft_check(argv[1][k], argv[1], k);
				k++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

int ft_check(char letter, char *str, int ct)
{
	int x = 0;

	while (x <= ct)
	{
		if (ct == x)
		{
			write(1, &letter, 1);
			return (0);
		}
		if (str[x] == letter)
			return (0);
		x++;
	}

	return (0);
}
