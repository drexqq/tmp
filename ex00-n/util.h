/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghlee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:35:59 by sunghlee          #+#    #+#             */
/*   Updated: 2020/12/06 09:19:07 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

void	put_str(char *str);
int		str_len(char *str);
char	*str_cat(char *dest, char *src);
int		str_cmp(char *key, char *src);
char	*str_ncpy(char *input, int n);

#endif
