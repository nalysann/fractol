/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 14:22:15 by nalysann          #+#    #+#             */
/*   Updated: 2020/10/06 14:22:18 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

typedef struct	s_draw
{
	int		type;
	int		sizex;
	int		size_line_int;
	int		max_iter;
	int		palette;
	double	scale;
	double	shift_re;
	double	shift_im;
	double	param_re;
	double	param_im;
}				t_draw;

#endif
