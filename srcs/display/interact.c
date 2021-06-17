#include "fractol.h"

static void	interact_key4(int k, t_vars *v)
{
	int		f;
	t_fol	*fol;

	fol = v->fol;
	f = v->fol->fractal;
	if (k == UP_ARROW)
		fol->pos_left[f] = alg_cplx(1, fol->pos_left[f], 0.1, make_cplx(0, 1));
	if (k == DOWN_ARROW)
		fol->pos_left[f] = alg_cplx(1, fol->pos_left[f], -0.1, make_cplx(0, 1));
	if (k == RIGHT_ARROW)
		fol->pos_left[f] = alg_cplx(1, fol->pos_left[f], -0.1, make_cplx(1, 0));
	if (k == LEFT_ARROW)
		fol->pos_left[f] = alg_cplx(1, fol->pos_left[f], 0.1, make_cplx(1, 0));
	if (k == UP_ARROW || k == DOWN_ARROW || k == RIGHT_ARROW || k == LEFT_ARROW)
	{
		refresh(v);
	}
}

static void	interact_key3(int k, t_vars *v)
{
	t_cplx	z;
	int		f;

	f = v->fol->fractal;
	z = coord_to_scale(v->fol, 400, 400, f);
	if (k == NUM_ADD && v->fol->fractal != FERN)
	{
		printf("zoom\n");
		v->fol->zoom[v->fol->fractal] *= 0.5;
		v->fol->dis_zoom[v->fol->fractal]++;
		v->fol->pos_left[f] = make_cplx(z.x - v->fol->zoom[f] / 2,
				z.y - v->fol->zoom[f] / 2);
		refresh(v);
	}
	if (k == NUM_MINUS && v->fol->fractal != FERN)
	{
		printf("diszoom\n");
		v->fol->zoom[v->fol->fractal] *= 2;
		v->fol->dis_zoom[v->fol->fractal]--;
		v->fol->pos_left[f] = make_cplx(z.x - v->fol->zoom[f] / 2,
				z.y - v->fol->zoom[f] / 2);
		refresh(v);
	}
	interact_key4(k, v);
}

static void	interact_key2(int keycode, t_vars *v)
{
	if (keycode == NUM_4)
		color_add_i_to_c(v->color, -1, 'r');
	if (keycode == NUM_5)
		color_add_i_to_c(v->color, -1, 'g');
	if (keycode == NUM_6)
		color_add_i_to_c(v->color, -1, 'b');
	if (keycode == NUM_7)
		color_add_i_to_c(v->color, 1, 'r');
	if (keycode == NUM_8)
		color_add_i_to_c(v->color, 1, 'g');
	if (keycode == NUM_9)
		color_add_i_to_c(v->color, 1, 'b');
	if (keycode >= NUM_4 && keycode <= NUM_9)
	{
		print_rgb(*(v->color));
		refresh(v);
	}
	interact_key3(keycode, v);
}

int	interact_key(int keycode, t_vars *v)
{
	int	i;

	i = 1;
	if (keycode == ESC)
	{
		mlx_destroy_window(v->mlx, v->win);
		exit(ft_exit(NO_ERROR, v));
	}
	if (keycode == NUM_1)
		i = 1;
	if (keycode == NUM_2 && v->fol->fractal != FERN)
		i = 2;
	if (keycode == NUM_3 && v->fol->fractal != FERN)
		i = 3;
	if (keycode >= NUM_1 && keycode <= NUM_3)
	{
		v->color = &v->fol->colors[v->fol->fractal][i];
		printf("color %d selected\n", i);
	}
	interact_key2(keycode, v);
	return (0);
}
