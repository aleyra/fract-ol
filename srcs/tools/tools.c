#include "fractol.h"

t_cplx	coord_to_scale(t_fol *fol, int i, int j, int f)
{
	t_cplx	z;

	z = make_cplx(fol->pos_left[f].x + fol->zoom[f] * i / RES_X,
			fol->pos_left[f].y + fol->zoom[f] * j / RES_Y);
	return (z);
}

int	coord_to_scale_fern_x(t_fol fol, t_cplx z)
{
	double	x;

	x = z.x * RES_X / (fol.fern_max.x - fol.fern_min.x) + fol.pos_left[FERN].x;
	return ((int)x);
}

int	coord_to_scale_fern_y(t_fol fol, t_cplx z)
{
	double	y;

	y = z.y * RES_Y / (fol.fern_max.y - fol.fern_min.y) + fol.pos_left[FERN].y;
	return ((int)y);
}
