#include "dict.h"
#include "util.h"
#include "print_number.h"
#include <unistd.h>
#include <stdio.h>

int	g_n;

void	print_digit(int len, t_dict *dict)
{
	char	*digit;
	int		i;

	if (len > 3)
	{
		i = 0;
		digit = (char *)malloc(sizeof(char) * (len + 1));
		while (i < len)
			digit[i++] = '0';
		digit[i] = '\0';
		digit[0] = '1';
		find_value(digit, dict);
		free(digit);
	}
	return ;
}

void	print_three(char *input, t_dict *dict)
{
	char	*one;

	one = str_ncpy(input, 1);
	if (one[0] != '0')
	{
		find_value(one, dict);
		write(1, " ", 1);
		find_value("100", dict);
	}
	free(one);
	return ;
}

int		check_two_numbers(int len, char *two, t_dict *dict)
{
	int	i;

	i = 0;
	while (dict[++i].key != 0)
	{
		if (str_cmp(two, dict[i].key) == 0)
		{
			find_value(two, dict);
			write(1, " ", 1);
			print_digit(len - 1, dict);
			return (2);
		}
	}
	i = -1;
	two[1] = '0';
	while (dict[++i].key != 0)
	{
		if (str_cmp(two, dict[i].key) == 0)
		{
			find_value(two, dict);
			return (1);
		}
	}
	return (0);
}

int		print_two(int len, char *input, t_dict *dict)
{
	char	*two;
	int		c;

	two = str_ncpy(input, 2);
	c = check_two_numbers(len, two, dict);
	if (c == 2)
		return (2);
	else if (c == 1)
		return (1);
	free(two);
	return (-1);
}

void	print_one(int len, char *input, t_dict *dict)
{
	char	*one;
	
	one = str_ncpy(input, 1);
	if (input[0] == '0' && g_n == 1)
		find_value(one, dict);
	else if (input[0] == '0' && len > 3)
	{
		print_digit(len, dict);
		write(1, " ", 1);
	}
	else if (input[0] != '0' && len > 3)
	{
		find_value(one, dict);
		write(1, " ", 1);
		print_digit(len, dict);
	}
	else if (input[0] != '0' && len == 1)
		find_value(one, dict);
	free(one);
}
