#include "fractol.h"

int	ft_exit(int err)
{
	if (err != NO_ERROR)
	{
		printf("Error\n");
		if (err == ERROR_MAIN_PARAM)
		{
			printf("A parameter must be passed on the command line to define ");
			printf("what type of fractal will be viewed\nEnter 'Julia' or ");
			printf("'Mandelbrot'\n");
		}
		if (err == ERROR_MALLOC)
			printf("A malloc didn't work\n");
	}
	return (err);
}
