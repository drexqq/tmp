/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghlee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 15:09:18 by sunghlee          #+#    #+#             */
/*   Updated: 2020/12/06 09:12:13 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "file.h"
#include "util.h"
#include "print_number.h"
#include "trim.h"
#include <stdio.h>

int	g_space = 0;

t_dict	*make_dict_map(char **split_str)
{
	t_dict	*dict;
	int		len;
	int		i;
	int		j;

	len = 0;
	while (split_str[len] != 0)
		len++;
	dict = (t_dict *)malloc(sizeof(t_dict) * len);
	if (!dict)
		return (0);
	i = 0;
	j = 0;
	while (i < (len / 2))
	{
//		printf("%s/\n", lr_trim(split_str[j]));
		dict[i].key = lr_trim(split_str[j++]);
		dict[i].value = ft_split(split_str[j++], " ");
		i++;
	}
	i = 0;
	return (dict);
}

int		get_value_len(char **value)
{
	int	len;

	len = 0;
	while (value[len] != 0)
		len++;
	return (len);
}

void	print_value(char **value)
{
	int	len;
	int	i;
	int	j;

	len = get_value_len(value);
	i = 0;
	j = 0;
	while (i < len)
	{
		j = 0;
		while (value[i][j] != 0)
		{
			write(1, &value[i][j], 1);
			j++;
		}
		if (i + 1 < len)
			write(1, " ", 1);
		i++;
	}
}

void	find_value(char *input, t_dict *dict)
{
	int	i;

	i = 0;
	while (dict[i].key != 0)
	{
		if (str_cmp(input, dict[i].key) == 0)
		{
			print_value(dict[i].value);
			return ;
		}
		i++;
	}
}

void	check_value(char *input, t_dict *dict)
{
	int		len;

	len = str_len(input);
	while (len > 0)
	{	
		if (*input == '0')
			g_space = 1;
		else
			g_space = 0;
		if (len % 3 == 2)
		{
			if (print_two(len, input, dict) == 2)
			{
				len--;
				input++;
			}
		}
		else if (len % 3 == 1)
			print_one(len, input, dict);
		else if (len % 3 == 0)
			print_three(input, dict);
		len--;
		input++;
		if (len > 0 && g_space == 0)
			write(1, " ", 1);
	}
}
