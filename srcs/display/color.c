#include "fractol.h"

int	create_trgb(t_rgb color)
{
	return (color.t << 24 | color.r << 16 | color.g << 8 | color.b);
}

void	incre_color(t_rgb *color, int i)
{
	color->r += i;
	if (color->r > 255)
	{
		color->r = color->r % 256;
		color->g += i;
	}
	if (color->g > 255)
	{
		color->g = color->g % 256;
		color->b += i;
	}
	if (color->b > 255)
	{
		color->b = color->b % 256;
		incre_color(color, i);
	}
}

void	init_color(t_rgb *color, int r, int g, int b)
{
	color->t = 0;
	color->r = r;
	color->g = g;
	color->b = b;
}
