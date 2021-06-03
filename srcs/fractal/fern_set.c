#include "fractol.h"

static void	init_fern3(t_fol *fol)
{
	fol->fern[1][1].mat_2_2[2] = -0.005;
	fol->fern[1][1].mat_2_2[3] = 0.93;
	fol->fern[1][1].mat_1_2[0] = -0.002;
	fol->fern[1][1].mat_1_2[1] = 0.5;
	fol->fern[1][1].p = 84 + fol->fern[1][0].p;
	fol->fern[1][1].max = 2;
	fol->fern[1][2].mat_2_2[0] = 0.035;
	fol->fern[1][2].mat_2_2[1] = -0.2;
	fol->fern[1][2].mat_2_2[2] = 0.16;
	fol->fern[1][2].mat_2_2[3] = 0.04;
	fol->fern[1][2].mat_1_2[0] = -0.09;
	fol->fern[1][2].mat_1_2[1] = 0.02;
	fol->fern[1][2].p = 7 + fol->fern[1][1].p;
	fol->fern[1][2].max = -1;
	fol->fern[1][3].mat_2_2[0] = -0.04;
	fol->fern[1][3].mat_2_2[1] = 0.2;
	fol->fern[1][3].mat_2_2[2] = 0.16;
	fol->fern[1][3].mat_2_2[3] = 0.04;
	fol->fern[1][3].mat_1_2[0] = 0.083;
	fol->fern[1][3].mat_1_2[1] = 0.12;
	fol->fern[1][3].p = 7 + fol->fern[1][2].p;
	fol->fern[1][3].max = 8;
}

static void	init_fern2(t_fol *fol)
{
	fol->fern[0][2].mat_2_2[2] = 0.23;
	fol->fern[0][2].mat_2_2[3] = 0.22;
	fol->fern[0][2].mat_1_2[0] = 0;
	fol->fern[0][2].mat_1_2[1] = 1.6;
	fol->fern[0][2].p = 7 + fol->fern[0][1].p;
	fol->fern[0][2].max = 0;
	fol->fern[0][3].mat_2_2[0] = -0.15;
	fol->fern[0][3].mat_2_2[1] = 0.28;
	fol->fern[0][3].mat_2_2[2] = 0.26;
	fol->fern[0][3].mat_2_2[3] = 0.24;
	fol->fern[0][3].mat_1_2[0] = 0;
	fol->fern[0][3].mat_1_2[1] = 0.44;
	fol->fern[0][3].p = 7 + fol->fern[0][2].p;
	fol->fern[0][3].max = 10;
	fol->fern[1][0].mat_2_2[0] = 0;
	fol->fern[1][0].mat_2_2[1] = 0;
	fol->fern[1][0].mat_2_2[2] = 0;
	fol->fern[1][0].mat_2_2[3] = 0.25;
	fol->fern[1][0].mat_1_2[0] = 0;
	fol->fern[1][0].mat_1_2[1] = -0.4;
	fol->fern[1][0].p = 2;
	fol->fern[1][0].max = -2;
	fol->fern[1][1].mat_2_2[0] = 0.95;
	fol->fern[1][1].mat_2_2[1] = 0.005;
	init_fern3(fol);
}

void	init_fern(t_fol *fol, int f)
{
	fol->zoom[f] = 4;
	fol->dis_zoom[f] = 0;
	fol->pos_left[f] = make_cplx(-2, -2);
	fol->deg[f] = 2;
	fol->it_tmp[f] = 0;
	fol->it[f] = 300;
	fol->fern[0][0].mat_2_2[0] = 0;
	fol->fern[0][0].mat_2_2[1] = 0;
	fol->fern[0][0].mat_2_2[2] = 0;
	fol->fern[0][0].mat_2_2[3] = 0.16;
	fol->fern[0][0].mat_1_2[0] = 0;
	fol->fern[0][0].mat_1_2[1] = 0;
	fol->fern[0][0].p = 1;
	fol->fern[0][0].max = -3;
	fol->fern[0][1].mat_2_2[0] = 0.85;
	fol->fern[0][1].mat_2_2[1] = 0.04;
	fol->fern[0][1].mat_2_2[2] = -0.04;
	fol->fern[0][1].mat_2_2[3] = 0.85;
	fol->fern[0][1].mat_1_2[0] = 0;
	fol->fern[0][1].mat_1_2[1] = 1.6;
	fol->fern[0][1].p = 85 + fol->fern[0][0].p;
	fol->fern[0][1].max = 3;
	fol->fern[0][2].mat_2_2[0] = 0.2;
	fol->fern[0][2].mat_2_2[1] = -0.26;
	init_fern2(fol);
}

t_cplx	formula_fern(t_cplx z, t_fol *fol)
{
	t_cplx	res;
	t_cplx	d;

	d = div_cplx(z, fol->c[FERN]);//chercher fol->c[FERN]
	res.x = cos(d.y) * (exp(d.x) - exp(-d.x)) / 2;
	res.y = sin(d.y) * (exp(d.x) - exp(-d.x)) / 2;
	return (res);
}
