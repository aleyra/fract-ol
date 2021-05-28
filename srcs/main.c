#include "fractol.h"

int	main(int ac, char *av[])
{
	t_vars	v;
	t_rgb 	color;//

	if (ac == 1 || ac >= 3)
		return (ft_exit(ERROR_MAIN_PARAM));
	if (ft_strcmp(av[1], "Julia") != 0 && ft_strcmp(av[1], "Mandelbrot") != 0)
		return (ft_exit(ERROR_MAIN_PARAM));
	v.mlx = mlx_init();
	if (!v.mlx)
		return (ft_exit(ERROR_MLX));
	v.win = mlx_new_window(v.mlx, RES_X, RES_Y, "fractol");
	if (!v.mlx)
		return (ft_exit(ERROR_MLX));
	printf("ici\n");//
	v.data->img = mlx_new_image(v.mlx, RES_X, RES_Y);
	printf("la\n");//
	if (!v.data->img)
		return (ft_exit(ERROR_MLX));
	v.data->addr = mlx_get_data_addr(v.data->img, &v.data->bits_per_pix,
			&v.data->line_len, &v.data->endian);
	if (!v.data->addr)
		return (ft_exit(ERROR_MLX));
	color.i = 123456;//
	my_mlx_pixel_put(v.data, 400, 400, color);//fct to call
	mlx_put_image_to_window(v.mlx, v.win, v.data->img, 0, 0);
	mlx_hook(v.win, 17, 1L << 2, win_close, &v);
	mlx_key_hook(v.win, interact_key, &v);
	mlx_loop(v.mlx);
	return (ft_exit(NO_ERROR));
}
