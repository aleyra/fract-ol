#include "fractol.h"

static void	result_in_color(t_vars *v, double it, double i, double j)
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
		nb = it * 3 / fol->it[fol->fractal];
		my_mlx_pixel_put(v->win, i, j, degraded_color(fol->color1, fol->color2, nb - (int)nb));
	}
	else
		my_mlx_pixel_put(v->win, i, j, black);
}

void	fractal(t_vars *v)
{
	int		i;
	int		j;
	double	it;
	t_cplx	z;
	t_fol	*fol;

	fol = v->fol;
	i = 0;
	while (i < RES_X)
	{
		j = 0;
		while (j < RES_Y)
		{
			if (fol->fractal == JULIA)
				z = make_cplx(fol->pos_left[JULIA].x + fol->zoom[JULIA] * i
						/ RES_X, fol->pos_left[JULIA].y + fol->zoom[JULIA] * j
						/ RES_Y);
			else
			{
				z = make_cplx(0, 0);
				fol->z[fol->fractal] = make_cplx(fol->pos_left[fol->fractal].x
						+ fol->zoom[fol->fractal] * i / RES_X,
						fol->pos_left[fol->fractal].y + fol->zoom[fol->fractal]
						* j / RES_Y);
	printf("la\n");//
			}
			it = 0;
			while (it < fol->it[fol->fractal] && module_cplx_pow2(z) < 4)
			{
				if (fol->fractal < 2)
					z = alg_cplx(1, mult_cplx(z, z), 1, fol->z[fol->fractal]);
				else
				{
					printf("for bonus\n");//
					break ;//
				}
				it++;
				result_in_color(v, it, i, j);
			}
			j++;
		}
		i++;
	}
}
