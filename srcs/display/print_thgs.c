#include "fractol.h"

static void	print_rgb(t_rgb *rgb)
{
	printf("%d,%d,%d\n", rgb->r, rgb->g, rgb->b);
}

void	print_fol(t_fol *fol)
{
	printf("fractal = %d\n", fol->fractal);
	print_rgb(fol->color1);
	print_rgb(fol->color2);
	//a finir
}
