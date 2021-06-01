#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "fcntl.h"
# include "stdio.h"
# include "mlx.h"

# define SIZE 800
# define RES_X SIZE
# define RES_Y SIZE
# define NB_FRACTALS 2

/* Structs for fract-ol ***************************************************** */

typedef struct s_vars	t_vars;
typedef struct s_data	t_data;
typedef struct s_rgb	t_rgb;
typedef struct s_fol	t_fol;
typedef enum e_error	t_error;
typedef enum e_key		t_key;
typedef enum e_fractal	t_fractal;

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
	int			fractal;
	t_rgb		color1;
	t_rgb		color2;
	long double	zoom[NB_FRACTALS];
	int			dis_zoom[NB_FRACTALS];
	t_cplx		pos_left[NB_FRACTALS];
	int			deg[NB_FRACTALS];
	double		it_tmp[NB_FRACTALS];
	int			it[NB_FRACTALS];
	t_cplx		z[NB_FRACTALS];
	int			deg_mandelbrot[3];
	void		(*init_fractal[NB_FRACTALS])(t_fol *, int);
};

struct s_vars
{
	void	*win;
	void	*mlx;
	t_data	data;
	t_fol	*fol;
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
t_rgb	degraded_color(t_rgb c1, t_rgb c2, double p);
int		ft_exit(int err, t_vars *v);
int		win_close(t_vars *v);
int		interact_key(int keycode, t_vars *v);
void	my_mlx_pixel_put(t_data *data, int x, int y, t_rgb color);

/* fct in fractal *********************************************************** */
void	fractal(t_vars *v);
void	init_julia(t_fol *fol, int f);
void	init_mandelbrot(t_fol *fol, int f);

/* fct in mana_struct ******************************************************* */
int		init_fractal(t_vars *v, char *str);
void	init_fol(t_fol *fol);

#endif
