/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghlee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:54:03 by sunghlee          #+#    #+#             */
/*   Updated: 2020/12/05 14:55:14 by sunghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_H
# define SPLIT_H

# include <stdlib.h>

int		is_in_charset(char c, char *charset);
char	**get_words(char *str, char *charset);
char	*str_cpy(char *str, char *charset, int start);
void	fill_words(char *str, char *charset, char **words);
char	**ft_split(char *str, char *charset);

#endif
