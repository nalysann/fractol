/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 14:58:14 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/22 14:58:14 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

typedef struct	s_draw
{
	int		type;
	int		size_x;
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	delta_re;
	double	delta_im;
	double	p_re;
	double	p_im;
	int		max_iter;
}				t_draw;

#endif
