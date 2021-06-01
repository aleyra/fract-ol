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
