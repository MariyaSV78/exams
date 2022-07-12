#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_mini
{
	int	x;
	int	y;
	char	bg;
	float	X;
	float	Y;
	float	R;
	char	type;
	char	color;
}	t_mini;

int	ft_error(char *str)
{
	int	i;
	
	i = 0;
	while(str[i])
		i++;
	write(1, str, i);
	return (1);
}

void	ft_free(char **data, t_mini *mini)
{
	int	y;

	if (data)
	{
		y = 0;
		while(y < mini->y)
			free(data[y++]);
		free(data);
	}
}

void	ft_print_data(char **data, t_mini *mini)
{
	int	y;

	if (data)
	{
		y = 0;
		while(y < mini->y)
		{
			write(1, data[y], mini->x);
			write(1, "\n", 1);
			y++;
		}
	}
}

void	ft_print_circle(char **array, t_mini *mini)
{
	int 	x;
	int	y;
	float	dest;

	y = 0;
	while (y < mini->y)
	{
		x = 0;
		while (x < mini->x)
		{
			dest = (x - mini->X) * (x - mini->X) + (y - mini->Y) * (y - mini->Y);
			if (dest <= mini->R * mini->R)
			{
				if ((mini->type == 'C') || (mini->type == 'c' && (dest > (mini->R -1) * (mini->R - 1))))
					array[y][x] = mini->color;	
			}
			x++;	
		}
		y++;
	}
}

int	ft_get_circle(FILE *file, char **array, t_mini *mini)
{
	int	count;
	
	while((count = fscanf(file, "%c %f %f %f %c\n", &mini->type, &mini->X, &mini->Y, &mini->R, &mini->color))== 5)
	{
		if(mini->R  > 0 && (mini->type == 'c' || mini->type == 'C'))
			ft_print_circle(array, mini);
		else
			return(1);
	}
	if (count == -1)
		return(0);
	if (count != 5)
		return (1);
	return (0); 
}

char	**ft_get_data(FILE *file, t_mini *mini)
{
	int	count;
	int	x;
	int	y;
	char	**array;

	array = NULL;
	count = fscanf(file, "%d %d %c\n", &mini->x, &mini->y, &mini->bg);
	if(count == 3 && mini->x > 0 && mini->x <= 300 && mini->y > 0 && mini->y <= 300)
	{
		array = (char **)malloc(sizeof(char *) * mini->y);
		if(!array)
			return(NULL);
		y = 0;
		while(y < mini->y)
		{
			array[y] = (char *)malloc(sizeof(char) * mini->x);
			if(!array[y])
				return(NULL);
			x = 0;
			while(x < mini->x)
			{
				array[y][x] = mini->bg;
				x++;
			}
			y++;
		}
		if (ft_get_circle(file, array, mini))
			return (NULL);		
	}
	return (array);
}

int	main(int argc, char **argv)
{
	FILE	*file;
	t_mini	mini;
	char	**data;

	if(argc != 2)
		return (ft_error("Error: argument\n"));
	file = fopen(argv[1], "r");
	if(file && (data = ft_get_data(file, &mini)))
		ft_print_data(data, &mini);
	else
	{
		if(file)
			fclose(file);
		ft_free(data, &mini);
		return(ft_error("Error: Operation file corrupted"));
	}
	ft_free(data, &mini);
	return (0);
}

 
