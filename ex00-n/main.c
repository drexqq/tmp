/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghlee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:39:01 by sunghlee          #+#    #+#             */
/*   Updated: 2020/12/06 09:19:41 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "valid_param.h"
#include "util.h"
#include "dict.h"
#include "file.h"
#include <stdio.h>

int	g_n;

char	*set_find_str(int argc, char *argv[])
{
	char	*find;

	if (argc == 3)
		find = argv[2];
	else if (argc == 2 || argc == 1)
		find = argv[1];
	g_n = str_len(find);
	return (find);
}

int	set_fd(int argc, char *argv[])
{
	int	fd;

	if (argc == 3)
		fd = open(argv[1], O_RDONLY);
	else if (argc == 2 || argc == 1)
		fd = open("numbers.dict", O_RDONLY);
	return (fd);
}

char	*set_file_str(int argc, char *argv[], int fd)
{
	char	*file_str;

	if (argc == 3)
		file_str = get_file_str(fd, argv[1]);
	else if (argc == 2 || argc == 1)
		file_str = get_file_str(fd, "numbers.dict");
	return (file_str);
}

int		main(int argc, char *argv[])
{
	char	*find;
	char	*file_str;
	int	fd;
	
	find = set_find_str(argc, argv);
	fd = set_fd(argc, argv);
	if (fd == -1)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	if (ch_argv(argc, argv) == 0 || ch_argc(argc) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	file_str = set_file_str(argc, argv, fd);
	if (argc == 1)
	{
		put_str(file_str);
		return (0);
	}
	check_value(find, make_dict_map(get_split_str(file_str)));
	write(1, "\n", 1);
	return (0);
}
