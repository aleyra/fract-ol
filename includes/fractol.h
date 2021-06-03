#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "fcntl.h"
# include "stdio.h"
# include "mlx.h"

# define SIZE 800
# define RES_X SIZE
# define RES_Y SIZE
# define NB_FRACTALS 3

/* Structs for fract-ol ***************************************************** */

typedef struct s_vars	t_vars;
typedef struct s_data	t_data;
typedef struct s_rgb	t_rgb;
typedef struct s_fol	t_fol;
typedef struct s_fern	t_fern;
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

struct s_fern {
	int		proba;
	t_cplx	mat[2];
	t_cplx	c;
};


struct s_fol {
	int			fractal;
	t_rgb		colors[NB_FRACTALS][4];
	long double	zoom[NB_FRACTALS];
	int			dis_zoom[NB_FRACTALS];
	t_cplx		pos_left[NB_FRACTALS];
	int			deg[NB_FRACTALS];
	double		it_tmp[NB_FRACTALS];
	int			it[NB_FRACTALS];
	t_cplx		c[NB_FRACTALS];
	t_fern		fern[4];
	t_cplx		fern_min;
	t_cplx		fern_max;
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
	SCROLL_UP = 4,
	SCROLL_DOWN = 5,
	ESC = 53,
	LEFT_ARROW = 123,
	RIGHT_ARROW = 124,
	DOWN_ARROW = 125,
	UP_ARROW = 126,
};

enum e_fractal {
	JULIA,
	MANDELBROT,
	FERN
};

/* fct in display *********************************************************** */
int		create_trgb(t_rgb color);
t_rgb	set_random_color(void);
t_rgb	color_add_i(t_rgb color, int i);
t_rgb	degraded_color(t_rgb c1, t_rgb c2, double p);
int		ft_exit(int err, t_vars *v);
int		win_close(t_vars *v);
int		interact_key(int keycode, t_vars *v);
int		interact_mouse(int keycode, int x, int y, t_vars *v);
void	my_mlx_pixel_put(t_data *data, int x, int y, t_rgb color);
void	print_rgb(t_rgb rgb);
void	print_cplx(t_cplx z);
void	print_fol(t_fol *fol);

/* fct in fractal *********************************************************** */
void	init_fern(t_fol *fol, int f);
void	fractal_fern(t_vars *v);
void	fractal(t_vars *v);
void	init_julia(t_fol *fol, int f);
t_cplx	formula_julia(t_cplx z, t_fol *fol);
void	init_mandelbrot(t_fol *fol, int f);
t_cplx	formula_mandelbrot(t_cplx z, t_fol *fol);

/* fct in mana_struct ******************************************************* */
t_rgb	init_rgb_black(void);
t_rgb	init_rgb_light_kaki(void);
t_rgb	init_rgb_blue(void);
t_rgb	init_rgb_grey(void);
t_rgb	init_rgb_color(int r, int g, int b);
int		init_fractal(t_vars *v, char *str);
void	init_fol(t_fol *fol);

/* fct in tools ************************************************************* */
t_cplx	coord_to_scale(t_fol *fol, int i, int j, int f);
int		coord_to_scale_fern_x(t_fol fol, t_cplx z);
int		coord_to_scale_fern_y(t_fol fol, t_cplx z);

#endif
