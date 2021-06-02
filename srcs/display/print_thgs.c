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
	printf("color 1 :");
	print_rgb(fol->color1);
	printf("color 2 :");
	print_rgb(fol->color2);
	printf("zoom[%d] = %Lf\n", fol->fractal, fol->zoom[fol->fractal]);
	printf("dis_zoom[%d] = %d\n", fol->fractal, fol->dis_zoom[fol->fractal]);
	printf("pos_left[%d] = ", fol->fractal);
	print_cplx(fol->pos_left[fol->fractal]);
	printf("deg[%d] = %d\n", fol->fractal, fol->deg[fol->fractal]);
	printf("it_tmp[%d] = %f\n", fol->fractal, fol->it_tmp[fol->fractal]);
	printf("it[%d] = %d\n", fol->fractal, fol->it[fol->fractal]);
	printf("c[%d] = ", fol->fractal);
	print_cplx(fol->c[fol->fractal]);
}
