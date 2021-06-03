#include "fractol.h"

int	init_fractal(t_vars *v, char *str)
{
	v->fol = malloc(sizeof(t_fol));
	if (!(v->fol))
		return (ERROR_MALLOC);
	if (ft_strcmp(str, "Julia") == 0)
		v->fol->fractal = JULIA;
	else if (ft_strcmp(str, "Mandelbrot") == 0)
		v->fol->fractal = MANDELBROT;
	else if (ft_strcmp(str, "Fern") == 0)
		v->fol->fractal = FERN;
	else
		return (ERROR_MAIN_PARAM);
	init_fol(v->fol);
	return (NO_ERROR);
}

void	init_fol(t_fol *fol)
{
	fol->colors[JULIA][0] = init_rgb_black();
	fol->colors[JULIA][1] = init_rgb_light_kaki();
	fol->colors[JULIA][2] = init_rgb_blue();
	fol->colors[JULIA][3] = init_rgb_grey();
	fol->colors[MANDELBROT][0] = init_rgb_black();
	fol->colors[MANDELBROT][1] = init_rgb_light_kaki();
	fol->colors[MANDELBROT][2] = init_rgb_blue();
	fol->colors[MANDELBROT][3] = init_rgb_grey();
	fol->colors[FERN][0] = init_rgb_black();
	fol->colors[FERN][1] = init_rgb_color(0, 255, 0);
	fol->init_fractal[JULIA] = init_julia;
	fol->init_fractal[MANDELBROT] = init_mandelbrot;
	fol->init_fractal[FERN] = init_fern;
}
