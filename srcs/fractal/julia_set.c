#include "fractol.h"

//f = fol->fractal
void	init_julia(t_fol *fol, int f)
{
	fol->zoom[f] = 4;
	fol->dis_zoom[f] = 0;
	fol->pos_left[f] = make_cplx(-2, -2);
	fol->deg[f] = 2;
	fol->it_tmp[f] = 0;
	fol->it[f] = 300;//10000 if f == 14
	fol->c[f] = make_cplx(-0.8, 0.156);
}