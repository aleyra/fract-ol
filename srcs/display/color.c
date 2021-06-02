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

t_rgb	color_add_i(t_rgb color, int i)
{
	t_rgb	res;

	res.r = color.r + i;
	if (res.r > 255)
		res.r = res.r % 255;
	res.g = color.g + i;
	if (res.g > 255)
		res.g = res.g % 255;
	res.b = color.b + i;
	if (res.b > 255)
		res.b = res.b % 255;
	return (res);
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
