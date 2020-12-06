/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghlee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 15:10:38 by sunghlee          #+#    #+#             */
/*   Updated: 2020/12/06 09:12:55 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

int	g_space;

typedef	struct		s_dict
{
	char	*key;
	char	**value;
}					t_dict;

t_dict				*make_dict_map(char	**split_str);
int					get_value_len(char **value);
void				print_value(char **value);
void				find_value(char *input, t_dict *dict);
void				check_value(char *input, t_dict *dict);

#endif
