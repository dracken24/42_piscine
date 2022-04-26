/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 23:45:24 by tparadis          #+#    #+#             */
/*   Updated: 2022/03/14 00:08:54 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

int				does_contain(long long int num);
int				is_all_zero(char *number);
void			find_number(char *num);
long long int	read_num(char *str);
int				is_numeric(char c);
long long int	ft_atoi(char *number, int start);

int				get_file_size(int fildes);
int				reset_file(char *file, int fildes);
char			*get_dict(int size, int fildes);
int				get_full_num(char *str);
int				get_num_length(int nb);
int				get_offset(int number);
int				get_index_from_highest(int highest);

void			print_multiple(int multi);
void			print_unit(char c, char *number, int highest);
void			print_num(char *number, int highest, int offset);
int				print_offset(int offset, char *num, int highest);

char			*get_number_word(int nb);
int				handle_stwenty(int i, char *num, int *highest);
int				handle_normal(char *num, char *number, int *highest, int i);
int				handle_offset(char *num, int *highest, int i, char *number);

int				validate_line(char *line);
int				put_line_two(char *line, int count, int i, char *buff);
int				put_line(char *line, char *buff);

extern char				*g_dict;
extern char				*g_snum;
extern long long int	g_numlist[33];

#endif
