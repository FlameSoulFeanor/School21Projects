#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_zone
{
	int width;
	int height;
	char back;
}	t_zone;

typedef struct s_shape
{
	char type;
	float x;
	float y;
	float width;
	float height;
	char clr;
}	t_shape;

size_t ft_strlen(const char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return(i);
}

int error_message(char *msg, int ret)
{
	write(1, msg, ft_strlen(msg));
	return (ret);
}

int clean_all(FILE *file, char *draw)
{
	fclose(file);
	if (draw)
		free(draw);
	return (1);
}

void draw_drawing(char *draw, t_zone *zone)
{
	int i = 0;
	while(i < zone->height)
	{
		write(1, draw + (i * zone->width), zone->width);
		write(1, '\n', 1);
		i++;
	}
}

int check_zone(t_zone *zone)
{
	return(zone->width > 0 && zone->width <= 300 && zone->height > 0 && zone->height <= 300);
}

int get_zone(FILE *file, t_zone *zone)
{
	int scan_ret;
	if (!( scan_ret = fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &zone->back)) != 3)
		return (0);
	if (!check_zone(zone))
		return(0);
	if (scan_ret == -1)
		return(0);
	return(1);
}

char *paint_back(t_zone *zone)
{
	char *draw;
	int i = 0;
	if (!(draw = (char *)malloc(sizeof(char) * (zone->width * zone->height))))
		return (NULL);
	while (i < zone->width * zone->height)
		draw[i++] = zone->back;
	return (draw);
}

int draw_shapes(FILE *file, char **draw, t_zone *zone)
{
	t_shape tmp;
	int scan_ret;

	
}

int main(int argc, char **argv)
{
	FILE *file;
	t_zone zone;
	char *draw;

	zone.back = 0;
	zone.height = 0;
	zone.width = 0;
	if (argc != 2)
		return(error_message("Error: argument\n", 1));
	if (!(file = fopen(argv[1], "r")))
		return(error_message("Error: Operation file corrupted\n", 1));
	if (!get_zone(file, &zone))
		return(clean_all(file, NULL) && error_message("Error: Operation file corrupted\n", 1));
	if (!(draw = paint_back(&zone)))
		return(clean_all(file, NULL) && error_message("Error: malloc failed\n", 1));
	if (!draw_shapes(file, &draw, &zone))
		return(clean_all(file, draw) && error_message("Error: Operation file corrupted\n", 1));
	draw_drawing(draw, &zone);
	clean_all(file, draw);
	return(0);
}
