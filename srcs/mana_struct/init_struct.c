#include "fractol.h"

int	init_fractal(t_fol *fol, char *str)
{
	if (ft_strcmp(str, "Julia") == 0)
		fol->fractal = JULIA;
	else if (ft_strcmp(str, "Mandelbrot") == 0)
		fol->fractal = MANDELBROT;
	else
		return (ERROR_MAIN_PARAM);
	return (NO_ERROR);
}

void	init_fol(t_fol *fol)
{
	fol->color = set_random_color();
}
