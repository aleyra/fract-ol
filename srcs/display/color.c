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

void	color_add_i_to_c(t_rgb *res, int i, char c)
{
	if (c == 'r')
	{
		res->r = res->r + i;
		if (res->r > 255)
			res->r = 0;
		if (res->r < 0)
			res->r = 255;
	}
	if (c == 'g')
	{
		res->g = res->g + i;
		if (res->g > 255)
			res->g = 0;
		if (res->g < 0)
			res->g = 255;
	}
	if (c == 'b')
	{
		res->b = res->b + i;
		if (res->b > 255)
			res->b = 0;
		if (res->b < 0)
			res->b = 255;
	}
	res->i = create_trgb(*res);
}

//inspired by qpupier
t_rgb	degraded_color(t_rgb c1, t_rgb c2, double p)
{
	t_rgb	res;

	res.r = c1.r + (c2.r - c1.r) * p;
	res.g = c1.g + (c2.g - c1.g) * p;
	res.b = c1.b + (c2.b - c1.b) * p;
	res.i = create_trgb(res);
	return (res);
}
