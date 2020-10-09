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
# include "draw.h"
# include "image.h"

# define WIDTH				1024
# define HEIGHT				768

# define FRACTAL_TYPES		8

# define SCALE_DEF			0.005
# define MAX_ITER_DEF		100
# define MAX_ITER_CAP		10000

# define MOVE_DELTA			10.0
# define ZOOM_DELTA			1.1
# define MAX_ITER_DELTA		1

typedef enum	e_type
{
	T_MANDELBROT = 1,
	T_JULIA,
	T_BURNING_SHIP,
	T_TRICORN,
	T_MULTIBROT3,
	T_MULTIJULIA3,
	T_JULIACORN,
	T_BUFFALO,
}				t_type;

typedef enum	e_palette
{
	P_RAINBOW = 1,
	P_MONOCHROME,
	P_PASTEL,
	P_COLD,
}				t_palette;

typedef struct	s_fractol
{
	void		*mlx_ptr;
	int			sizex;
	int			sizey;
	void		*win_ptr;
	t_img		img;
	t_cl		cl;
	t_draw		data;
	int			is_fixed;
}				t_fractol;

#endif
