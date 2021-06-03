#include "fractol.h"

t_cplx	coord_to_scale(t_fol *fol, int i, int j, int f)
{
	t_cplx	z;

	z = make_cplx(fol->pos_left[f].x + fol->zoom[f] * i / RES_X,
			fol->pos_left[f].y + fol->zoom[f] * j / RES_Y);
	return (z);
}
