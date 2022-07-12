# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	f_strlen (const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_print_str (char *str)
{
	if (str == NULL)
		return (write (1, "(null)", 6));
	return (write (1, str, f_strlen(str)));
}

int	ft_print_dec(int nbr)
{
	int j;
	char ch;

	j = 0;

	if (nbr == -2147483648)
		return (write (1, "-2147383648", 11));
	if (nbr < 0)
	{
		j += write (1, "-", 1);
		nbr = -nbr;
	}
	if (nbr > 9)
		j += ft_print_dec(nbr / 10);
	ch = "0123456789"[nbr % 10];
	j += write (1, &ch, 1);
	return (j);
}

int	ft_print_hexa(unsigned int hexa)
{
	int	j;
	char nb;

	j = 0;
	if (hexa > 15)
		j += ft_print_hexa(hexa / 16);
	nb = "0123456789ABCDEF"[hexa % 16];
	j += write (1, &nb, 1);
	return (j);
}

int	ft_printf(const char *line_for_print, ...)
{
	int	j;
	va_list ap;

	va_start(ap, line_for_print);
	j = 0;
	while (*line_for_print)
	{
		if (*line_for_print == '%')
		{
			line_for_print++;
			if (*line_for_print == 's')
				j += ft_print_str(va_arg(ap, char	*));
			if (*line_for_print == 'd')
				j += ft_print_dec (va_arg(ap, int));
			if (*line_for_print == 'x')
				j += ft_print_hexa (va_arg(ap, unsigned int));
			line_for_print++;
			
		}
		else
		{
			j += write (1, line_for_print, 1);
			line_for_print++;
		}
	}
	va_end (ap);
	return (j);
}

int	main()
{
	int N1, N2;


	{
	printf ("--------------------------------string s -------------------------------------");
	char line[] = "\n printing %s succeeded \n";
	char s[] = "one line";
	N1 = printf (line, s);
	N2 = ft_printf (line, s);
	printf ("\n\t number of characters printf = %i, ft_printf = %i\n", N1, N2);
	}
	{
	char line[] = "\n printing %s succeeded \n";
	char s[] = "";
	N1 = printf (line, s);
	N2 = ft_printf (line, s);
	printf ("\n\t number of characters printf = %i, ft_printf = %i\n", N1, N2);
	}
	{
	char line[] = "\n printing %s succeeded \n";
	char *s;
	s = NULL;
	N1 = printf (line, s);
	N2 = ft_printf (line, s);
	printf ("\n\t number of characters printf = %i, ft_printf = %i\n", N1, N2);
	}

		{
	printf ("--------------------------------hexadecimal x -------------------------------------");
	char line[] = "\n printing one hexadecimal %x succeeded \n";
	int x = -1;
	N1 = printf (line, x);
	N2 = ft_printf (line, x);
	printf ("\n\t number of characters printf = %i, ft_printf = %i\n", N1, N2);
	}

	{
	char line[] = "\n printing one hexadecimal %x succeeded \n";
	int x = 0;
	N1 = printf (line, x);
	N2 = ft_printf (line, x);
	printf ("\n\t number of characters printf = %i, ft_printf = %i\n", N1, N2);
	}
	{
	char line[] = "\n printing one hexadecimal %x succeeded \n";
	int x = 0xA;
	N1 = printf (line, x);
	N2 = ft_printf (line, x);
	printf ("\n\t number of characters printf = %i, ft_printf = %i\n", N1, N2);
	}
	{
	char line[] = "\n printing one hexadecimal %x succeeded \n";
	int x = 0x31A;
	N1 = printf (line, x);
	N2 = ft_printf (line, x);
	printf ("\n\t number of characters printf = %i, ft_printf = %i\n", N1, N2);
	}
	{
	char line[] = "\n printing one hexadecimal %x succeeded \n";
	int x = 675;
	N1 = printf (line, x);
	N2 = ft_printf (line, x);
	printf ("\n\t number of characters printf = %i, ft_printf = %i\n", N1, N2);
	}

	{
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
}
