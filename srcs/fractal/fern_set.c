#include "fractol.h"

static void	init_fern_max_min(t_fol *fol)
{
	fol->fern_min.x = -3;
	fol->fern_max.x = 3;
	fol->fern_min.y = 0;
	fol->fern_max.y = 10;
}

//https://en.wikipedia.org/wiki/Barnsley_fern
void	init_fern(t_fol *fol, int f)
{
	fol->zoom[f] = 4;
	fol->dis_zoom[f] = 0;
	fol->pos_left[f] = make_cplx(-3, 0);
	fol->deg[f] = 2;
	fol->it_tmp[f] = 0;
	fol->it[f] = 110000;
	fol->fern[0].proba = 1;
	fol->fern[0].mat[0] = make_cplx(0, 0);
	fol->fern[0].mat[1] = make_cplx(0, 0.16);
	fol->fern[0].c = make_cplx(0, 0);
	fol->fern[1].proba = fol->fern[0].proba + 85;
	fol->fern[1].mat[0] = make_cplx(0.85, -0.04);
	fol->fern[1].mat[1] = make_cplx(0.04, 0.85);
	fol->fern[1].c = make_cplx(0, 1.6);
	fol->fern[2].proba = fol->fern[1].proba + 7;
	fol->fern[2].mat[0] = make_cplx(0.2, 0.23);
	fol->fern[2].mat[1] = make_cplx(-0.26, 0.22);
	fol->fern[2].c = make_cplx(0, 1.6);
	fol->fern[3].proba = fol->fern[2].proba + 7;
	fol->fern[3].mat[0] = make_cplx(-0.15, 0.26);
	fol->fern[3].mat[1] = make_cplx(0.28, 0.24);
	fol->fern[3].c = make_cplx(0, 0.44);
	init_fern_max_min(fol);
}

void	fractal_fern(t_vars *v)
{
	int		rng;
	int		it;
	int		j;
	t_cplx	z;
	t_fern	*fern;

	fern = v->fol->fern;
	z = make_cplx(0, 0);
	it = 0;
	while (it < v->fol->it[FERN])
	{
		rng = rand() % 100;
		j = 0;
		while (rng >= fern[j].proba)
			j++;
		z = make_cplx(fern[j].mat[0].x * z.x + fern[j].mat[1].x * z.y
				+ fern[j].c.x, fern[j].mat[0].y * z.x + fern[j].mat[1].y * z.y
				+ fern[j].c.y);
		my_mlx_pixel_put(&v->data, coord_to_scale_fern_x(*v->fol, z),
			coord_to_scale_fern_y(*v->fol, z), v->fol->colors[FERN][1]);
		it++;
	}
}
