/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 11:56:47 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/14 11:56:48 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "cl_data.h"
# include "image.h"

# include "ft_complex.h"

# define FRACTAL_TYPES		3
# define PALETTE_TYPES		4

# define MIN_RE_DEF			(-2.0)
# define MAX_RE_DEF			(2.0)

# define P_RE_DEF			(0.0)
# define P_IM_DEF			(0.0)

# define MAX_ITER_DEF		42
# define MAX_ITER_CAP		10000
# define MAX_ITER_SHIFT		4

# define MOVE_DELTA			0.05

typedef enum	e_type
{
	T_MANDELBROT,
	T_JULIA,
	T_BURNUNG_SHIP,
}				t_type;

typedef enum	e_palette
{
	P_MONOCHROME,
}				t_palette;

typedef struct	s_draw
{
	int			type;
	int			sizex;
	double		minx;
	double		maxx;
	double		miny;
	double		maxy;
	double		deltax;
	double		deltay;
	double		px;
	double		py;
	int			max_iter;
}				t_draw;

typedef struct	s_fractol
{
	void		*mlx_ptr;
	int			size_x;
	int			size_y;
	void		*win_ptr;
	t_img		img;
	t_cl		cl;
	t_draw		data;

}				t_fractol;

#endif
