#include "fractol.h"

//inspired from https://en.wikipedia.org/wiki/Julia_set
/******************************************************************************/
/* in this fct 																  */
/* z[0] is x when z=x+iy													  */
/* z[1] is y when z=x+iy													  */
/* idem for c[2]															  */
/******************************************************************************/
float	julia_set_reccur_x(float zn[2], float c[2])
{
	float	xn1;

	xn1 = zn[0] * zn[0] - zn[1] * zn[1] + c[0];
	return (xn1);
}

float	julia_set_reccur_y(float zn[2], float c[2])
{
	float	yn1;

	yn1 = 2 * zn[0] * zn[1] + c[1];
	return (yn1);
}

int	display_julia(t_vars *v, float z0[2], float c[2], int i_max)
{
	// t_rgb	color;
	float	*z;
	int		i;
	int		xy[2];

	(void)v;//
	i = 0;
	// init_color(&color, 0, 0, 125);
	z = malloc(2 * sizeof(float));
	if (!z)
		return (ERROR_MALLOC);
	z[0] = z0[0];
	z[1] = z0[1];
	xy[0] = z[0] * 100 + 1920 / 2;//?
	xy[1] = -1 * z[1] * 100 + 1080 / 2;//?
	printf("c = %f + i %f\n", c[0], c[1]);//
	while (i < i_max)//&& xy[0] < 1920 && xy[1] < 1080)
	{
		// color.i = create_trgb(color);
		// my_mlx_pixel_put(v->data, xy[0], xy[1], color);//?
		printf("%d : %f + i %f\n", i, z[0], z[1]);
		z[0] = julia_set_reccur_x(z, c);
		z[1] = julia_set_reccur_y(z, c);
		xy[0] = z[0] * 100 + 1920 / 2;//?
		xy[1] = -1 * z[1] * 100 + 1080 / 2;//?
		// incre_color(&color, 25);
		i++;
	}
	free(z);
	return (NO_ERROR);
}
