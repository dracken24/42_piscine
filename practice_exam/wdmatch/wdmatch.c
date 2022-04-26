
#include <unistd.h>

void ft_putstr(char *str);

int main(int argc, char **argv)
{
	int	min;
	int	max;

	min = 0;
	max = 0;
	if (argc == 3) 
	{
		while (argv[2][min] != '\0')
		{
			if (argv[2][min] == argv[1][max])
			{
				max++;
				if (argv[1][max] == '\0')
				{
					ft_putstr(argv[1]);
					write(1, "\n", 1);
					return (0);
				}
			}
			min++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
}