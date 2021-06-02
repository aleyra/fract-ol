#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, t_rgb color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < RES_X && y < RES_Y)
	{
		dst = data->addr + (y * data->line_len + x * data->bits_per_pix / 8);
		*(unsigned int *) dst = color.i;
	}
}
