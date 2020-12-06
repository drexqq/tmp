/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghlee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:25:35 by sunghlee          #+#    #+#             */
/*   Updated: 2020/12/06 09:18:06 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include <fcntl.h>
# include <unistd.h>
# include "split.h"
# include "util.h"

int		get_file_size(int fd, char *dict_name);
char	*get_file_str(int fd, char *dict_name);
char	**get_str_per_line(char *file_str);
char	**get_split_str(char *file_str);

#endif
