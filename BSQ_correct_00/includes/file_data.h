/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_data.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:13:34 by iamongeo          #+#    #+#             */
/*   Updated: 2022/03/16 23:29:56 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_DATA_H
# define FILE_DATA_H
# define RBUFF_SIZE 1000000

typedef struct s_file_data
{
	int		fdesc;
	int		height;
	int		width;
	char	empty;
	char	obst;
	char	full;
	char	**map;
}	t_file_data;

typedef struct s_buff
{
	char	*buff;
	int		size;
}	t_buff;

char	**ft_split(char *str, char *charset);
int		print_map_error(void);
int		validate_map(t_file_data *fdata, char *buff, int head_offset, int size);
int		find_bsq(t_file_data *fdata);
void	free_map(t_file_data *fdata);
int		ft_strlen(char *str);

#endif
