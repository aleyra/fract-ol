#include "fractol.h"

int	main()
{
	t_vars	v;
	int		res_xy[2];
	float	z[2];
	float	c[2];

	res_xy[0] = 1920;
	res_xy[1] = 1080;
	z[0] = 0;
	z[1] = 0;
	c[0] = 1;
	c[1] = -1;
	// v.mlx = mlx_init();
	// v.win = mlx_new_window(v.mlx, res_xy[0], res_xy[1], "fractol");
	// v.data->img = mlx_new_image(v.mlx, res_xy[0], res_xy[1]);
	// v.data->addr = mlx_get_data_addr(v.data->img, &v.data->bits_per_pix,
	// 		&v.data->line_len, &v.data->endian);
	display_julia(&v, z, c, 10);
	// mlx_put_image_to_window(v.mlx, v.win, v.data->img, 0, 0);
	// mlx_hook(v.win, 17, 1L << 2, win_close, &v);
	// mlx_key_hook(v.win, interact_key, &v);
	// mlx_loop(v.mlx);
	return (NO_ERROR);
}
