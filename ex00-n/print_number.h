#ifndef PRINT_NUMBERS_H
# define PRINT_NUMBERS_H

# include <stdlib.h>

int	g_n;

void	print_digit(int len, t_dict *dict);
void	print_three(char *input, t_dict *dict);
int		check_two_numbers(int len, char *two, t_dict *dict);
int		print_two(int len, char *input, t_dict *dict);
void	print_one(int len, char *input, t_dict *dict);

#endif
