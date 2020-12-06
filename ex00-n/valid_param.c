#include "util.h"
int	ch_argc(int argc)
{
	if (argc == 1 || argc == 2 || argc == 3)
		return (1);
	return (0);
}

int	ch_argv_zero(int argc, char *argv[])
{
	int len;

	if (argc == 3)
	{
		len = str_len(argv[2]);
		if (argv[2][0] == '0' && len > 1)
			return (0);
	}
	else if (argc == 2)
	{
		len = str_len(argv[1]);
		if (argv[1][0] == '0' && len > 1)
			return (0);
	}
	return (1);
}

int	ch_argv(int argc, char *argv[])
{
	int  i;

	i = 0;
	if (ch_argv_zero(argc, argv) == 0)
		return (0);
	if (argc == 3)
	{
		while (argv[2][i] != 0)
		{
			if (argv[2][i] < '0' || argv[2][i] > '9')
				return (0);
			i++;
		}
	}
	else if (argc == 2)
	{
		while (argv[1][i] != 0)
		{
			if (argv[1][i] < '0' || argv[1][i] > '9')
				return (0);
			i++;
		}
	}
	return (1);
}
