#include "fractol.h"

void	print_rgb(t_rgb rgb)
{
	printf("%d,%d,%d\n", rgb.r, rgb.g, rgb.b);
}

void	print_cplx(t_cplx z)
{
	printf("%f + i * %f\n", z.x, z.y);
}

void	print_fol(t_fol *fol)
{
	printf("fractal = %d\n", fol->fractal);
	printf("zoom[%d] = %Lf\n", fol->fractal, fol->zoom[fol->fractal]);
	printf("dis_zoom[%d] = %d\n", fol->fractal, fol->dis_zoom[fol->fractal]);
	printf("pos_left[%d] = ", fol->fractal);
	print_cplx(fol->pos_left[fol->fractal]);
	printf("it[%d] = %d\n", fol->fractal, fol->it[fol->fractal]);
	printf("c[%d] = ", fol->fractal);
	print_cplx(fol->c[fol->fractal]);
}
