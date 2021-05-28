#include "fractol.h"

int	create_trgb(t_rgb color)
{
	return (color.t << 24 | color.r << 16 | color.g << 8 | color.b);
}

//from qpupier
t_rgb	set_random_color(void)
{
	t_rgb	color;

	color.r = rand() % 255;
	color.g = rand() % 255;
	color.b = rand() % 255;
	color.t = 0;
	return (color);
}

void	init_color(t_rgb *color, int r, int g, int b)
{
	color->t = 0;
	color->r = r;
	color->g = g;
	color->b = b;
}
