/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghlee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:47:58 by sunghlee          #+#    #+#             */
/*   Updated: 2020/12/05 19:21:14 by sunghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split.h"

int		is_in_charset(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	**get_words(char *str, char *charset)
{
	int		i;
	int		flag;
	int		count;
	char	**words;

	i = 0;
	flag = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (is_in_charset(str[i], charset))
			flag = 0;
		else
		{
			if (flag == 0)
				count++;
			flag = 1;
		}
		i++;
	}
	words = (char **)malloc(sizeof(char *) * (count + 1));
	return (words);
}

char	*str_cpy(char *str, char *charset, int start)
{
	char	*dest;
	int		len;
	int		i;

	len = start;
	while (str[len] != '\0' && !is_in_charset(str[len], charset))
		len++;
	dest = (char *)malloc(sizeof(char) * (len - start + 1));
	if (!dest)
		return (0);
	i = 0;
	while (i < len - start)
	{
		dest[i] = str[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	fill_words(char *str, char *charset, char **words)
{
	int i;
	int s;
	int n;
	int flag;

	i = -1;
	n = -1;
	s = 0;
	flag = 0;
	while (str[++i] != '\0')
	{
		if (is_in_charset(str[i], charset))
			flag = 0;
		else if (flag == 0)
		{
			s = i;
			words[++n] = str_cpy(str, charset, s);
			flag = 1;
		}
	}
	words[++n] = 0;
}

char	**ft_split(char *str, char *charset)
{
	char	**words;

	words = get_words(str, charset);
	fill_words(str, charset, words);
	return (words);
}
