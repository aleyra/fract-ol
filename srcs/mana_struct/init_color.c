#include "fractol.h"

t_rgb	init_rgb_black(void)
{
	t_rgb	res;

	res.r = 0;
	res.g = 0;
	res.b = 0;
	res.t = 0;
	res.i = create_trgb(res);
	return (res);
}

t_rgb	init_rgb_light_kaki(void)
{
	t_rgb	res;

	res.r = 158;
	res.g = 195;
	res.b = 111;
	res.t = 0;
	res.i = create_trgb(res);
	return (res);
}

t_rgb	init_rgb_blue(void)
{
	t_rgb	res;

	res.r = 0;
	res.g = 0;
	res.b = 255;
	res.t = 0;
	res.i = create_trgb(res);
	return (res);
}

t_rgb	init_rgb_grey(void)
{
	t_rgb	res;

	res.r = 170;
	res.g = 170;
	res.b = 170;
	res.t = 0;
	res.i = create_trgb(res);
	return (res);
}
