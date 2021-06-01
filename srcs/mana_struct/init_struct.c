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
	fol->color1 = set_random_color();
	fol->color2 = set_random_color();
	fol->init_fractal[JULIA - 1] = init_julia;
	fol->init_fractal[MANDELBROT - 1] = init_mandelbrot;
}
