/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghlee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:34:01 by sunghlee          #+#    #+#             */
/*   Updated: 2020/12/06 09:18:53 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	put_str(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
}

int		str_len(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*str_cat(char *dest, char *src)
{
	int dl;
	int sl;

	dl = 0;
	sl = 0;
	while (*(dest + dl))
		dl++;
	while (*(src + sl))
	{
		*(dest + dl) = *(src + sl);
		dl++;
		sl++;
	}
	*(dest + dl) = '\0';
	return (dest);
}

int		str_cmp(char *key, char *src)
{
	int	i;

	i = 0;
	while (key[i] && src[i] && (key[i] == src[i]))
		i++;
	return (key[i] - src[i]);
}

char	*str_ncpy(char *input, int n)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * (n + 1));
	i = 0;
	while (i < n)
	{
		ret[i] = input[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
