#include "fractol.h"

static void	interact_key4(int keycode, t_vars *v)
{
	t_cplx	z;
	t_fol	*fol;
	int		f;

	fol = v->fol;
	f = fol->fractal;
	z = coord_to_scale(fol, 400, 400, f);
	if (keycode == UP_ARROW && v->fol->fractal != FERN)
	{
		printf("zoom\n");
		v->fol->zoom[v->fol->fractal] *= 0.5;
		v->fol->dis_zoom[v->fol->fractal]++;
		fol->pos_left[f] = make_cplx(z.x - fol->zoom[f] * 400 / RES_X,
				z.y - fol->zoom[f] * 400 / RES_Y);
		refresh(v);
	}
	if (keycode == DOWN_ARROW && v->fol->fractal != FERN)
	{
		printf("diszoom\n");
		v->fol->zoom[v->fol->fractal] *= 2;
		v->fol->dis_zoom[v->fol->fractal]--;
		fol->pos_left[f] = make_cplx(z.x - fol->zoom[f] * 400 / RES_X,
				z.y - fol->zoom[f] * 400 / RES_Y);
		refresh(v);
	}
}

static void	interact_key3(int keycode, t_vars *v)
{
	if (keycode == NUM_8)
	{
		color_add_i_to_c(v->color, 1, 'g');
		print_rgb(*(v->color));
	}
	if (keycode == NUM_9)
	{
		color_add_i_to_c(v->color, 1, 'b');
		print_rgb(*(v->color));
	}
	if (keycode >= NUM_4 && keycode <= NUM_9)
		refresh(v);
	interact_key4(keycode, v);
}

static void	interact_key2(int keycode, t_vars *v)
{
	if (keycode == NUM_4)
	{
		color_add_i_to_c(v->color, -1, 'r');
		print_rgb(*(v->color));
	}
	if (keycode == NUM_5)
	{
		color_add_i_to_c(v->color, -1, 'g');
		print_rgb(*(v->color));
	}
	if (keycode == NUM_6)
	{
		color_add_i_to_c(v->color, -1, 'b');
		print_rgb(*(v->color));
	}
	if (keycode == NUM_7)
	{
		color_add_i_to_c(v->color, 1, 'r');
		print_rgb(*(v->color));
	}
	interact_key3(keycode, v);
}

int	interact_key(int keycode, t_vars *v)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(v->mlx, v->win);
		exit(ft_exit(NO_ERROR, v));
	}
	if (keycode == NUM_1)
	{
		v->color = &v->fol->colors[v->fol->fractal][1];
		printf("color 1 selected\n");
	}
	if (keycode == NUM_2 && v->fol->fractal != FERN)
	{
		v->color = &v->fol->colors[v->fol->fractal][2];
		printf("color 2 selected\n");
	}
	if (keycode == NUM_3 && v->fol->fractal != FERN)
	{
		v->color = &v->fol->colors[v->fol->fractal][3];
		printf("color 3 selected\n");
	}
	interact_key2(keycode, v);
	return (0);
}
