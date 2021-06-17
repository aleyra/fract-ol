#include "fractol.h"

int	win_close(t_vars *v)
{
	mlx_destroy_window(v->mlx, v->win);
	exit(ft_exit(NO_ERROR, v));
	return (NO_ERROR);
}

void	refresh(t_vars *v)
{
	printf("refreshing...\n");
	mlx_destroy_image(v->mlx, v->data.img);
	v->data.img = mlx_new_image(v->mlx, RES_X, RES_Y);
	if (!v->data.img)
		exit(ft_exit(ERROR_MLX, v));
	v->data.addr = mlx_get_data_addr(v->data.img, &v->data.bits_per_pix,
			&v->data.line_len, &v->data.endian);
	if (!v->data.addr)
		exit(ft_exit(ERROR_MLX, v));
	if (v->fol->fractal != FERN)
		fractal(v);
	else
		fractal_fern(v);
	mlx_put_image_to_window(v->mlx, v->win, v->data.img, 0, 0);
}

void	zoom_in_out(t_vars *v, int x, int y, int key)
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
	if (key == SCROLL_UP)
	{
		printf("scroll diszoom\n");
		fol->zoom[f] *= 2;
		fol->dis_zoom[f]--;
	}
	else if (key == SCROLL_DOWN)
	{
		printf("scroll zoom\n");
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
