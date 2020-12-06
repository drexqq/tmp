#include <stdlib.h>
#include <stdio.h>

int	is_space(char c)
{
	return (((c >= 9 && c <= 13) || c == 32) ? 1 : 0);
}

int	count_char(char *str)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (str[i] != 0)
	{
		if (is_space(str[i]) == 0)
			count++;
		i++;
	}
	return (count);
}

char	*lr_trim(char *str)
{
	char	*a;
	int	flag;
	int	i;
	int	j;

	flag = 0;
	i = -1;
	while (str[++i] != 0)
		if (is_space(str[i]) == 1)
			flag = 1;
	if (flag == 1)
	{
		a = (char *)malloc(sizeof(char) * (count_char(str) + 1));
		i = -1;
		j = -1;
		while (str[++i] != 0)
			if (is_space(str[i]) == 0)
				a[++j] = str[i];
		a[++j] = 0;
		free(str);
		return (a);
	}
	return (str);
}
