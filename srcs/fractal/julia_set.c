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
	//int		xy[2];

	(void)v;//
	(void)c;//
	(void)i_max;//
	i = 0;
	// init_color(&color, 0, 0, 125);
	z = malloc(2 * sizeof(float));
	if (!z)
		return (ERROR_MALLOC);
	z[0] = z0[0];
	z[1] = z0[1];
	//?
	free(z);
	return (NO_ERROR);
}
