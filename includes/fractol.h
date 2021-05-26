#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "fcntl.h"
# include "stdio.h"
# include "mlx.h"

/* Structs for fract-ol ***************************************************** */

typedef struct s_vars	t_vars;
typedef struct s_data	t_data;
typedef struct s_rgb	t_rgb;
typedef enum e_error	t_error;
typedef enum e_key		t_key;

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
	float	fb;
	float	fg;
	float	fr;
};

enum e_error {
	NO_ERROR,
};

enum e_key{
	NO_KEY = 0,
	ESC = 53,
	LEFT_ARROW = 123,
	RIGHT_ARROW = 124,
	DOWN_ARROW = 125,
	UP_ARROW = 126,
};

/* fct in display *********************************************************** */
int	win_close(t_vars *v);
int	interact_key(int keycode, t_vars *v);
#endif
