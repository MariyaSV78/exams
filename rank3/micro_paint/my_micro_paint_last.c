#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_micro
{
	int	X;
	int	Y;
	char	bg;
	char	type;
	float	x;
	float	y;
	float	width;
	float	height;
	char	color;
} t_micro;

int	ft_error(char *str)
{
	int	i;

	if (!str)
		return (1);
	i = 0;
	while(str[i])
		i++;
	write(1, str, i);
	return(1);
}

void ft_free(FILE *file,char **data, t_micro *micro)
{
	int	y;

	fclose(file);
	if(data)
	{
		y = 0;
		while (y < micro->Y)
			free(data[y++]);
		free(data);
	}
}

void	ft_print(char **data, t_micro *micro)
{
	int	y;

	if(data)
	{
		y = 0;
		while (y < micro->Y)
		{
			write(1, data[y], micro->X);
			write(1, "\n", 1);
			y++;
		}	
	}
}

char	**ft_get_data(FILE *file, t_micro *micro)
{
	int	x;
	int	y;
	char	**array;

	if(fscanf(file, "%d %d %c\n", &micro->X, &micro->Y, &micro->bg) != 3)
		return (NULL);
	if(!(micro->X > 0 && micro-> X <= 300 && micro->Y > 0 && micro->Y <= 300))
		return (NULL);
	array = (char **)malloc(sizeof(char *) * micro->Y);
	if(!array)
		return(NULL);
	y = 0;
	while (y < micro->Y)
	{
		array[y] = (char *)malloc(sizeof(char) * micro->X);
		x = 0;
		while (x < micro->X)
		{
			array[y][x] = micro->bg;
			x++;
		}
		y++;
	}
	return (array);
}

void	ft_print_rect(char **data, t_micro *micro)
{
	int	x;
	int	y;
	float	c;

	c = 1.;
	y = 0;
	while(y < micro->Y)
	{
		x = 0;
		while(x < micro->X)
		{
			if ((float)x >= micro->x && (float)x <= (micro->x + micro->width) && ((float)y >= micro->y) && (float)y <= (micro->y + micro->height))
			{
				if (micro->type =='R' || (micro->type == 'r' && (((float)x - micro->x) <= c ||\
							 (micro->x + micro->width - (float)x) < c ||\
							 ((float)y - micro->y) <= c || (micro->y + micro->height - (float)y ) < c)))
					data[y][x] = micro->color;
			}
			x++;

		}
		y++;

	}
}

int	ft_get_rect(FILE *file, char **data, t_micro *micro)
{
	int	count;
	
	while((count = fscanf(file, "%c %f %f %f %f %c\n", &micro->type, &micro->x, &micro->y, &micro->width, &micro->height, &micro->color)) == 6)
	{
		if (!(micro->width > 0 && micro->height > 0 && (micro->type == 'r' || micro->type == 'R')))
			continue;
		ft_print_rect(data, micro);
	} 
	if (count == (-1))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**data;
	FILE	*file;
	t_micro	micro;

	if(argc != 2)
		return (ft_error("Error: arguments"));
	if(!(file = fopen(argv[1], "r")))
		return (ft_error("Error: Operation file corrupted"));
	if(!(data = ft_get_data(file, &micro)))
	{
		ft_free(file, data, &micro);
		return (ft_error("Error: Operation file corrupted"));
	}
	if(!(ft_get_rect(file, data, &micro)))
	{
		ft_free(file, data, &micro);
		return (ft_error("Error: Operation file corrupted"));
	}
	ft_print(data, &micro);
	ft_free(file, data, &micro);
	return (0);
}
