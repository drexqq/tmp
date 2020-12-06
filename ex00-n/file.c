/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghlee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 13:19:17 by sunghlee          #+#    #+#             */
/*   Updated: 2020/12/06 09:14:49 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include "file.h"
#include "split.h"

int		get_file_size(int fd, char *dict_name)
{
	char	c;
	int		s;

	s = 0;
	fd = open(dict_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	else
	{
		while (read(fd, &c, 1))
			s++;
	}
	close(fd);
	return (s);
}

char	**get_str_per_line(char *file_str)
{
	char	**str_per_line;

	str_per_line = ft_split(file_str, "\n");
	return (str_per_line);
}

char	*get_file_str(int fd, char *dict_name)
{
	char	*file_str;
	int		file_size;

	if (fd == -1)
		return (0);
	file_size = get_file_size(fd, dict_name);
	file_str = (char *)malloc(sizeof(char) * (file_size + 1));
	if (!file_str)
		return (0);
	read(fd, file_str, file_size);
	close(fd);
	return (file_str);
}

char	**get_split_str(char *file_str)
{
	char	**str_per_line;
	char	*str;
	int		len;
	int		i;

	i = -1;
	len = 0;
	str_per_line = get_str_per_line(file_str);
	while (str_per_line[++i] != 0)
		len += str_len(str_per_line[i]);
	str = (char *)malloc(sizeof(char) * (len + i + 1));
	len = i;
	if (!str)
		return (0);
	str[0] = 0;
	i = -1;
	while (str_per_line[++i] != 0)
	{
		str = str_cat(str, str_per_line[i]);
		if (i + 1 < len)
			str = str_cat(str, "\n");
	}
	return (ft_split(str, ":\n"));
}
