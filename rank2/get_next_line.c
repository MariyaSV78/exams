#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
//#include <sys/stat.h>

#define FD_MAX 1000

typedef struct	s_readbufer
{
	int	start;
	ssize_t	n;
	char	buf[BUFFER_SIZE];
}	t_readbufer;

int	ft_findend(char	*buf, int end, int n)
{
	while (end < n)
	{
		if (buf[end] == '\n')
			return (end);
		end++;	
	}
	return (end);
}

int	ft_len_line(char *line)
{
	unsigned int	i;

	i = 0;
	if (line == 0)
		return(i);
	while (line[i])
		i++;
	return (i);

}

char	*ft_newline(char *tmp_line, char *buf, int start, int end)
{
	int	j;
	char	*line;
	int		len_tmp_line;

	if (end == start)
		return (tmp_line);
	len_tmp_line = ft_len_line(tmp_line);
	line = (char *)malloc(sizeof(char) * (end - start + len_tmp_line + 2));
	if (!line)
		return (NULL);
	j =0;
	while (j < len_tmp_line)
	{
		line[j] = tmp_line[j];
		j++;
	}
	while (start < end)
		line[j++] = buf[start++];
	line[j] = '\0';
	free(tmp_line);
	return (line);
}

char	*get_next_line(fd)
{
	static t_readbufer	read_buf = {.start = 0};
	int	end;
	char	*line;

	if (BUFFER_SIZE < 0 || fd < 0 || fd == 1 || fd == 2 || fd >= FD_MAX)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (read_buf.start == 0)
			read_buf.n = read(fd, read_buf.buf, BUFFER_SIZE);
		if (read_buf.n < 0)
			return (NULL);
		if (read_buf.n == 0)
			return (line);
		end = ft_findend(read_buf.buf, read_buf.start, read_buf.n);
		if (end < read_buf.n)
		{
			line = ft_newline(line, read_buf.buf, read_buf.start, end + 1);
			read_buf.start = end + 1;
			return (line);
		}
		line = ft_newline(line, read_buf.buf, read_buf.start, end);
		read_buf.start = 0;
	}	
}

int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;
	int		i;

	if (argc < 1)
		return (0);
	if (argc == 1)
		fd = open("text.txt", O_RDONLY);
	fd = open(argv[1], O_RDONLY);
	if (!fd)
	{
		perror ("Error");
		exit (0);
	}
	i = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf ("\n%d: |%s|\n",i++, line);
	}
	close (fd);
	return (0);
}

/*int main (int args, char *argws[])
{
	FILE *file;
	int fd;
	char *line;

	if (args == 1)
		file = fopen("my_file_poeme.txt", "r");
	else
		file = fopen(argws[1], "r");
	if (!file) // открытие файла
	{
		perror("Error occured while opening file");
		return 1;
	}
	
	fd = fileno(file); // файл дескриптор,
	
	int i = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL){
		//	printf ("\n%d : |NULL|\n", i++);
			break;
		}
		printf ("\n%d : |%s|\n", i++, line);
	}
	fclose(file);
	return (0);
}*/
