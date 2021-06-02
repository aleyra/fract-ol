#include "fractol.h"

//f = fol->fractal
//https://fr.wikipedia.org/wiki/Ensemble_de_Mandelbrot
//singularity at point of Misiurewicz −0,1011 + 0,9563i
void	init_mandelbrot(t_fol *fol, int f)
{
	fol->zoom[f] = 4;
	fol->dis_zoom[f] = 0;
	fol->pos_left[f] = make_cplx(-2, -2);
	fol->deg[f] = 2;
	fol->it_tmp[f] = 0;
	fol->it[f] = 300;
	fol->c[f] = make_cplx(-0.1011, 0.9563);
}

t_cplx	formula_mandelbrot(t_cplx z, t_fol *fol)
{
	t_cplx	res;

	res = alg_cplx(1, mult_cplx(z, z), 1, fol->c[MANDELBROT]);
	return (res);
}
