#include "fractol.h"

static int	init_with_mlx(t_vars *v)
{
	v->mlx = mlx_init();
	if (!v->mlx)
		return (ft_exit(ERROR_MLX, v));
	v->win = mlx_new_window(v->mlx, RES_X, RES_Y, "fract'ol");
	if (!v->win)
		return (ft_exit(ERROR_MLX, v));
	v->data.img = mlx_new_image(v->mlx, RES_X, RES_Y);
	if (!v->data.img)
		return (ft_exit(ERROR_MLX, v));
	v->data.addr = mlx_get_data_addr(v->data.img, &v->data.bits_per_pix,
			&v->data.line_len, &v->data.endian);
	if (!v->data.addr)
		return (ft_exit(ERROR_MLX, v));
	return (NO_ERROR);
}

int	main(int ac, char *av[])
{
	t_vars	v;
	int		err;

	if (ac == 1 || ac >= 3)
		return (ft_exit(ERROR_MAIN_PARAM, &v));
	err = init_fractal(&v, av[1]);
	v.fol->init_fractal[v.fol->fractal - 1](v.fol, v.fol->fractal);
	if (err != NO_ERROR)
		return (ft_exit(err, &v));
	if (init_with_mlx(&v) != NO_ERROR)
		return (ft_exit(ERROR_MLX, &v));
	fractal(&v);
	printf("displaying...\n");
	mlx_put_image_to_window(v.mlx, v.win, v.data.img, 0, 0);
	mlx_hook(v.win, 17, 1L << 2, win_close, &v);
	mlx_key_hook(v.win, interact_key, &v);
	mlx_loop(v.mlx);
	return (ft_exit(NO_ERROR, &v));
}
