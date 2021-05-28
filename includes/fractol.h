#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "fcntl.h"
# include "stdio.h"
# include "mlx.h"

# define SIZE 800
# define RES_X SIZE
# define RES_Y SIZE

/* Structs for fract-ol ***************************************************** */

typedef struct s_vars	t_vars;
typedef struct s_data	t_data;
typedef struct s_rgb	t_rgb;
typedef struct s_fol	t_fol;
typedef enum e_error	t_error;
typedef enum e_key		t_key;
typedef enum e_fractal	t_fractal;


struct s_vars
{
	void	*win;
	void	*mlx;
	t_data	*data;
};

struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pix;
	int		line_len;
	int		endian;
};

struct s_rgb {
	int		i;
	int		t;
	int		b;
	int		g;
	int		r;
};

struct s_fol {
	int		fractal;
	t_rgb	color;
};

enum e_error {
	NO_ERROR,
	ERROR_MAIN_PARAM,
	ERROR_MLX,
	ERROR_MALLOC
};

enum e_key {
	NO_KEY = 0,
	ESC = 53,
	LEFT_ARROW = 123,
	RIGHT_ARROW = 124,
	DOWN_ARROW = 125,
	UP_ARROW = 126,
};

enum e_fractal {
	NONE,
	JULIA,
	MANDELBROT
};

/* fct in display *********************************************************** */
int		create_trgb(t_rgb color);
t_rgb	set_random_color(void);
void	init_color(t_rgb *color, int r, int g, int b);
int		ft_exit(int err);
int		win_close(t_vars *v);
int		interact_key(int keycode, t_vars *v);
void	my_mlx_pixel_put(t_data *data, int x, int y, t_rgb color);

/* fct in fractal *********************************************************** */
float	julia_set_reccur_x(float zn[2], float c[2]);
float	julia_set_reccur_y(float zn[2], float c[2]);
int		display_julia(t_vars *v, float z0[2], float c[2], int i_max);

/* fct in mana_struct ******************************************************* */
int		init_fractal(t_fol *fol, char *str);

#endif
