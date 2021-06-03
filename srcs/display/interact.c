#include "fractol.h"

int	win_close(t_vars *v)
{
	mlx_destroy_window(v->mlx, v->win);
	exit(ft_exit(NO_ERROR, v));
	return (NO_ERROR);
}

int	interact_key(int keycode, t_vars *v)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(v->mlx, v->win);
		exit(ft_exit(NO_ERROR, v));
	}
	return (0);
}

static void	refresh(t_vars *v)
{
	int		i;
	int		j;
	t_rgb	black;

	black = init_rgb_black();
	printf("refreshing...\n");
	if (v->fol->fractal != FERN)
		fractal(v);
	else
	{
		i = -1;
		while (++i < RES_X)
		{
			j = -1;
			while (++j < RES_Y)
				my_mlx_pixel_put(&v->data, i, j, black);
		}
		fractal_fern(v);
	}
	mlx_put_image_to_window(v->mlx, v->win, v->data.img, 0, 0);
}

static void	zoom_in_out(t_vars *v, int x, int y, int key)
{
	t_cplx	z;
	t_fol	*fol;
	int		f;

	fol = v->fol;
	f = fol->fractal;
	if (x < 0 || x >= RES_X || y < 0 || y >= RES_Y)
		return ;
	x = 0;
	z = coord_to_scale(fol, x, y, f);
	if (key == SCROLL_UP/* && fol->dis_zoom[f] > -3*/)
	{
		fol->zoom[f] *= 2;
		fol->dis_zoom[f]--;
	}
	else if (key == SCROLL_DOWN/* && fol->dis_zoom[f] < 50*/)
	{
		fol->zoom[f] *= 0.5;
		fol->dis_zoom[f]++;
	}
	fol->pos_left[f] = make_cplx(z.x - fol->zoom[f] * x / RES_X,
			z.y - fol->zoom[f] * y / RES_Y);
}

int	interact_mouse(int keycode, int x, int y, t_vars *v)
{
	if (keycode == SCROLL_UP || keycode == SCROLL_DOWN)
	{
		zoom_in_out(v, x, y, keycode);
		refresh(v);
	}
	return (0);
}
