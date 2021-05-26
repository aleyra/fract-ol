#include "fractol.h"

int	win_close(t_vars *v)
{
	mlx_destroy_window(v->mlx, v->win);
	free(v->data);
	exit(NO_ERROR);
	return (NO_ERROR);
}

int	interact_key(int keycode, t_vars *v)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(v->mlx, v->win);
		exit(NO_ERROR);
	}
	return (0);
}
