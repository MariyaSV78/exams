#include "ft_printf.h"
#include <stdio.h>

void	main()
{
	int N1, N2;

	{
	printf ("--------------------------------string s -------------------------------------");
	char line[] = "\n printing %s succeeded \n";
	N1 = printf (line, "one line");
	N2 = ft_printf (line, "one line");
	printf ("\n\t number of characters printf = %i, ft_printf = %i\n", N1, N2);
	}
	printf ("--------------------------------decimal d -------------------------------------");

	char line[] = "\n printing one decimal %d succeeded \n";
	int x = -1000000000;
	N1 = printf (line, x);
	N2 = ft_printf (line, x);
	printf ("\n\t number of characters printf = %i, ft_printf = %i\n", N1, N2);
	}
	{
	char line[] = "\n printing one decimal %d succeeded \n";
	int x = 145;
	N1 = printf (line, x);
	N2 = ft_printf (line, x);
	printf ("\n\t number of characters printf = %i, ft_printf = %i\n", N1, N2);
	}
	printf ("--------------------------------hexadecimal X -------------------------------------");
	{
	char line[] = "\n printing one hexadecimal %X succeeded \n";
	int x = -1;
	N1 = printf (line, x);
	N2 = ft_printf (line, x);
	printf ("\n\t number of characters printf = %i, ft_printf = %i\n", N1, N2);
	}
	{
	char line[] = "\n printing one hexadecimal %X succeeded \n";
	int x = 0;
	N1 = printf (line, x);
	N2 = ft_printf (line, x);
	printf ("\n\t number of characters printf = %i, ft_printf = %i\n", N1, N2);
	}
	{
	char line[] = "\n printing one hexadecimal %X succeeded \n";
	int x = 0xA;
	N1 = printf (line, x);
	N2 = ft_printf (line, x);
	printf ("\n\t number of characters printf = %i, ft_printf = %i\n", N1, N2);
	}
	{
	char line[] = "\n printing one hexadecimal %X succeeded \n";
	int x = 0x31A;
	N1 = printf (line, x);
	N2 = ft_printf (line, x);
	printf ("\n\t number of characters printf = %i, ft_printf = %i\n", N1, N2);
	}
	{
	char line[] = "\n printing one hexadecimal %X succeeded \n";
	int x = 675;
	N1 = printf (line, x);
	N2 = ft_printf (line, x);
	printf ("\n\t number of characters printf = %i, ft_printf = %i\n", N1, N2);
	}
}
