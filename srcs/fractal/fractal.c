#include "fractol.h"

static void	result_in_color(t_vars *v, int it, double i, double j)
{
	double	nb;
	t_cplx	z;
	t_rgb	black;
	t_fol	*fol;

	black.i = 0;
	fol = v->fol;
	z = make_cplx(0, 0);
	if (it < fol->it[fol->fractal])
	{
		nb = (double)it * 3 / (double)fol->it[fol->fractal];
		my_mlx_pixel_put(&v->data, i, j,
			degraded_color(fol->colors[(int)nb], fol->colors[(int)nb + 1],
				nb - (int)nb));
	}
	else
	{
		my_mlx_pixel_put(&v->data, i, j, black);
	}
}

static void	define_z_fol_c(int i, int j, t_fol *fol, t_cplx *z)
{
	if (fol->fractal == JULIA)
	{
		*z = make_cplx(fol->pos_left[JULIA].x + fol->zoom[JULIA] * i
				/ RES_X, fol->pos_left[JULIA].y + fol->zoom[JULIA] * j
				/ RES_Y);
	}
	else
	{
		*z = make_cplx(0, 0);
		fol->c[fol->fractal] = make_cplx(fol->pos_left[fol->fractal].x
				+ fol->zoom[fol->fractal] * i / RES_X,
				fol->pos_left[fol->fractal].y + fol->zoom[fol->fractal]
				* j / RES_Y);
	}
}

static	t_cplx	set_formula(t_fol *fol, t_cplx z)
{
	t_cplx	res;

	if (fol->fractal == JULIA)
		res = alg_cplx(1, mult_cplx(z, z), 1, fol->c[JULIA]);
	else//else if (fol->fractal == MANDELBROT) when bonus ON
		res = alg_cplx(1, mult_cplx(z, z), 1, fol->c[MANDELBROT]);
	//else add bonus
	return (res);
}

void	fractal(t_vars *v)
{
	int		i;
	int		j;
	int		it;
	t_cplx	z;
	t_fol	*fol;

	fol = v->fol;
	i = 0;
	while (i < RES_X)
	{
		j = 0;
		while (j < RES_Y)
		{
			define_z_fol_c(i, j, fol, &z);
			it = 0;
			while (it < fol->it[fol->fractal] && module_cplx_pow2(z) < 4)
			{
				z = set_formula(fol, z);
				it++;
			}
			result_in_color(v, it, i, j);
			j++;
		}
		i++;
	}
}
