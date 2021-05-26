/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:31:55 by lburnet           #+#    #+#             */
/*   Updated: 2021/05/26 13:52:53 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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

struct s_vars
{
	void	*win;
	void	*mlx;
	t_data	*img;
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
#endif
