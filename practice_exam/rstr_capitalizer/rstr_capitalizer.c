
#include <unistd.h>

void ft_alph_down(int argc, char **argv);
void ft_print(int argc, char **argv);

int main(int argc, char **argv)
{
	int i;
	int k;

	i = 1;
	if (argc >= 2)
	{
		ft_alph_down(argc, argv);
		while (i < argc)
		{
			k = 0;
			while (argv[i][k] != '\0')
			{
				if ((argv[i][k + 1] == ' ' || argv[i][k + 1] == '\t' || argv[i][k + 1] == '\0')
						&& argv[i][k] >= 'a' && argv[i][k] <= 'z')
					argv[i][k] -= 32;
				k++;
			}
			i++;
		}
	}
	ft_print(argc, argv);
	if (argc < 2)
		write (1, "\n", 1);
	return (0);
}

void    ft_alph_down(int argc, char **argv)
{
	int i;
	int k;

	i = 1;
	while (i < argc)
	{
		k = 0;
		while (argv[i][k] != '\0')
		{
			if (argv[i][k] >= 'A' && argv[i][k] <= 'Z')
				argv[i][k] += 32;
			k++;
		}
		i++;
	}
}

void    ft_print(int argc, char **argv)
{
	int i;
	int k;

	i = 1;
	while (i < argc)
	{
		k = 0;
		while (argv[i][k] != '\0')
		{
			write(1, &argv[i][k], 1);
			k++;
		}
		write(1, "\n", 1);
		i++;
	}
}
