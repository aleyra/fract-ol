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
	else
		return (ERROR_MAIN_PARAM);
	init_fol(v->fol);
	return (NO_ERROR);
}

void	init_fol(t_fol *fol)
{
	fol->colors[0] = init_rgb_black();
	fol->colors[1] = init_rgb_light_kaki();
	fol->colors[2] = init_rgb_blue();
	fol->colors[3] = init_rgb_grey();
	fol->init_fractal[JULIA - 1] = init_julia;
	fol->init_fractal[MANDELBROT - 1] = init_mandelbrot;
}
