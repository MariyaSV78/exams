#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int     X;
int     Y;
char    **drawing;

typedef struct s_rect
{
    float   px; // point coordinates;
    float   py;
    float   xsize; // size of rectangle;
    float   ysize;
    char    type; // type of rectangle and the char to draw it
    char    fill;
} rect;

void ft_prin(char *str)
{
    int i;

    i = 0;
    if (!str)
        exit(0);
    else
    {
        while(str[i])
            i++;
        write (1, str, i);
    }
}

void    ft_beckground(char bg)
{
    int x;
    int y;

    y = 0;
    drawing = malloc(sizeof(char *) * Y);
    while (y < Y)
    {
        x = 0;
        drawing[y] = malloc(sizeof(char) * X);
        while (x < X)
        {
            drawing[x][y] = bg;
            x++;
        }
        y++;
    }

}

void    ft_free()
{
    int y = 0;

    while (y < Y)
    {
        free(drawing[y]);
        y++;
    }
    free (drawing);
}

void    ft_paintpixel(int x, int y, rect r)
{
    //check if point xy is in the rectangle
	if (x >= r.px && x <= r.px + r.xsize && y >= r.py && y <= r.py + r.ysize)
    {
        if (r.type == 'R')
            drawing[y][x] = r.fill; //????????????????????????????????????
    }
    else 
    {
        //check if point is on the border
        //(control if there is a further away point that belongs to the rectangle)
        if (!(x - 1 >= r.px && x + 1 <= r.px + r.xsize && y - 1 >= r.py && y + 1 <= r.py + r.ysize))
            drawing[y][x] = r.fill;
    }

}

void ft_draw()
{
	int x, y = 0;

	//prints the drawing
	while (y < Y)
	{
		x = 0;
		while (x < X)
		{
			write(1, &drawing[y][x], 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

int ft_checkrect(FILE *fd)
{
    rect    r;
    int     res;
    int     x;
    int     y;

    res = fscanf(fd, "\n%c %f %f %f %f %c", &r.type, &r.px, &r.py, &r.xsize, &r.ysize, &r.fill);
  //res = -1 -> file is over
    if (res == -1)
        return (0);
    if (res < 6 || r.xsize <=0 || r.ysize <= 0 || (r.type != 'r' && r.type != 'R'))
        return (1);
    y = 0;
    while (y < Y)
    {
        x = 0;
        while (x < X)
        {
            ft_paintpixel(x, y, r);
            x++;
        }
        y++;
    }
    return (42);
}

int ft_checkfd(FILE *fd)
{
    char bg;
    int ret;

    if (fscanf(fd, "%d %d %c", &X,&Y,&bg)!= 3)
        return (1);
    if (X < 1 || Y < 1 || X > 300 || Y > 300)
        return (1);
    // setup the beckground
    ft_beckgrund(bg);
    //start reading rectangl, stop if error
    while (ret = ft_checkrect(fd)) // ????????????????????????????????????????
        if (ret == 1)
        {
            ft_free();
            return (1);
        }
    ft_draw();
    ft_free();
    return (0);
}


int main (int argc, char    **argv)
{
    FILE    *fd;

    if (argc == 2)
    {
        fd = fopen(argv[1], "r");
        if (fd && !ft_checkfd(fd))
        {
            fclose(fd);
            retrn (0);
        }
        if (fd)
            fclose(fd);
        ft_print("Error: Operation fie corruped\n");
    }
    else
        ft_print("Error: argument\n");

    return (1);
}