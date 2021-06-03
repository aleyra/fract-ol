#include "fractol.h"

static void	result_in_color_non_fern(t_vars *v, int it, double i, double j)
{
	double	nb;
	t_rgb	black;
	t_fol	*fol;

	fol = v->fol;
	black = init_rgb_black();
	if (it < fol->it[fol->fractal])
	{
		nb = (double)it * 3 / (double)fol->it[fol->fractal];
		my_mlx_pixel_put(&v->data, i, j,
			degraded_color(fol->colors[fol->fractal][(int)nb],
				fol->colors[fol->fractal][(int)nb + 1], nb - (int)nb));
	}
	else
		my_mlx_pixel_put(&v->data, i, j, black);
}

static void	define_z_fol_c(int i, int j, t_fol *fol, t_cplx *z)
{
	if (fol->fractal == JULIA)
	{
		*z = coord_to_scale(fol, i, j, JULIA);
	}
	else
	{
		*z = make_cplx(0, 0);
		fol->c[fol->fractal] = coord_to_scale(fol, i, j, fol->fractal);
	}
}

static	t_cplx	set_formula(t_fol *fol, t_cplx z)
{
	t_cplx	res;

	if (fol->fractal == JULIA)
	{
		res = formula_julia(z, fol);
	}
	else
		res = formula_mandelbrot(z, fol);
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
	i = -1;
	while (++i < RES_X)
	{
		j = -1;
		while (++j < RES_Y)
		{
			define_z_fol_c(i, j, fol, &z);
			it = -1;
			while (++it < fol->it[fol->fractal] && module_cplx_pow2(z) < 4)
				z = set_formula(fol, z);
			result_in_color_non_fern(v, it, i, j);
		}
	}
}
