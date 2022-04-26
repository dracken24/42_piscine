/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:45:24 by iamongeo          #+#    #+#             */
/*   Updated: 2022/03/16 22:41:01 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "file_data.h"

int	is_file_header_valid(char *buff)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (buff[i] == '\n')
			return (0);
	return ('0' <= buff[0] && buff[0] <= '9');
}

int	validate_and_set_map_chars(t_file_data *f_data, char *buff)
{
	char	em;
	char	ob;
	char	fu;

	em = 0;
	ob = 0;
	fu = 0;
	if (' ' <= *buff && *buff <= '~')
		em = *(buff++);
	if (' ' <= *buff && *buff <= '~')
		ob = *(buff++);
	if (' ' <= *buff && *buff <= '~')
		fu = *(buff++);
	if (em && ob && fu && em != ob && em != fu && ob != fu)
	{
		f_data->empty = em;
		f_data->obst = ob;
		f_data->full = fu;
		return (1);
	}
	return (0);
}

int	process_file(int file_desc, char *buff)
{
	t_file_data	f_data;
	int			read_count;
	int			i;

	i = -1;
	f_data.fdesc = file_desc;
	if (f_data.fdesc == -1)
		return (print_map_error());
	f_data.height = 0;
	read_count = read(f_data.fdesc, buff, RBUFF_SIZE);
	if (read_count < 6 || !is_file_header_valid(buff))
		return (print_map_error());
	while ('0' <= buff[++i] && buff[i] <= '9')
		f_data.height = (f_data.height * 10) + (buff[i] - '0');
	if (!validate_and_set_map_chars(&f_data, buff + i))
		return (print_map_error());
	while (buff[i++] != '\n')
		continue ;
	if (!validate_map(&f_data, buff, i, read_count))
		return (-1);
	find_bsq(&f_data);
	free_map(&f_data);
	close(f_data.fdesc);
	return (1);
}

int	open_file(char *file_name)
{
	return (open(file_name, O_RDONLY));
}

int	main(int argc, char *argv[])
{
	char	read_file_buff[RBUFF_SIZE];
	int		nb_files;
	int		i;

	if (argc == 1)
		process_file(0, read_file_buff);
	else
	{
		nb_files = argc - 1;
		i = -1;
		while (++i < argc - 1)
		{
			process_file(open_file(argv[i + 1]), read_file_buff);
			write(1, "\n", (i < (nb_files - 1)));
		}
	}
	return (0);
}
