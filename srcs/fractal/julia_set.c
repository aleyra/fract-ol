#include "fractol.h"

//f = fol->fractal
void	init_julia(t_fol *fol, int f)
{
	fol->zoom[f] = 4;
	fol->dis_zoom[f] = 0;
	fol->pos_left[f] = make_cplx(-2, -2);
	fol->it[f] = 300;
	fol->c[f] = make_cplx(-0.8, 0.156);
}

t_cplx	formula_julia(t_cplx z, t_fol *fol)
{
	t_cplx	res;

	res = alg_cplx(1, mult_cplx(z, z), 1, fol->c[JULIA]);
	return (res);
}
