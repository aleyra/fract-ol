#include "fractol.h"

//inspired from https://en.wikipedia.org/wiki/Julia_set
/******************************************************************************/
/* in this fct 																  */
/* z[0] is x when z=x+iy													  */
/* z[1] is y when z=x+iy													  */
/* idem for c[2]															  */
/******************************************************************************/
void	normal_julia_set(int esc_radius, float c[2])
{
	int		ij[2];
	float	z[2];
	float	t;
	int		n;
	int		n_max;

	ij[0] = 0;
	n = 0;
	n_max = 1000;
	while (ij[0] < 1920)
	{
		ij[1] = 0;
		while (ij[1] < 1080)
		{
			z[0] = scaled_coord_pix(ij[0], esc_radius);
			z[1] = scaled_coord_pix(ij[1], esc_radius);
			while (z[0] * z[0] + z[1] * z[1] < esc_radius * esc_radius
				&& n < n_max)
			{
				t = z[0] * z[0] - z[1] * z[1];
				z[1] = 2 * z[0] * z[1] + c[1];
				z[0] = t + c[0];
				n++;
			}
			// if (n == n_max)
        	// 	return black;
    		// else
        	// 	return n;
			(ij[1])++;
		}
		(ij[0])++;
	}
}
