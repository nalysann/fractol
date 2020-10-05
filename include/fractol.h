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

# define FRACTAL_TYPES		8

# define MIN_RE_DEF			(-2.0)
# define MAX_RE_DEF			(2.0)

# define P_RE_DEF			(0.0)
# define P_IM_DEF			(0.0)

# define MAX_ITER_DEF		100
# define MAX_ITER_CAP		10000

# define MOVE_DELTA			0.02

typedef enum	e_type
{
	T_NONE,
	T_MANDELBROT,
	T_JULIA,
	T_BURNING_SHIP,
	T_BONUS_1,
	T_BONUS_2,
	T_BONUS_3,
	T_BONUS_4,
	T_BONUS_5,
}				t_type;

/*
** int_params
**   0 type
**   1 size_x
**   2 size_y
**   3 max_iter
**
** double_params
**   0 min_re
**   1 max_re
**   2 mix_im
**   3 max_im
**   4 delta_re
**   5 delta_im
**   6 p_re
**   7 p_im
*/

typedef struct	s_fractol
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_cl	cl;
	int		int_params[INT_PARAMS];
	double	double_params[double_PARAMS];
	int		*palette;
	int		is_fixed;
}				t_fractol;

#endif
