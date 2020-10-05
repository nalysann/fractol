/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 18:19:24 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/14 18:19:26 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_funs.h"
#include "fractol.h"
#include "mouse.h"

static double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void			zoom(int button, int x, int y, t_fractol *fractol)
{
	double	re;
	double	im;
	double	interpolation;
	double	zoom;

	if (button == BUT_DOWN)
	{
		zoom = 0.95;
	}
	else
	{
		zoom = 1.05;
	}
	re = (double)x / fractol->int_params[1] * (fractol->double_params[1] - fractol->double_params[0]) + fractol->double_params[0];
	im = (double)y / fractol->int_params[2] * (fractol->double_params[3] - fractol->double_params[2]) + fractol->double_params[2];
	interpolation = 1.0 / zoom;
	fractol->double_params[0] = interpolate(re, fractol->double_params[0], interpolation);
	fractol->double_params[2] = interpolate(im, fractol->double_params[2], interpolation);
	fractol->double_params[1] = interpolate(re, fractol->double_params[1], interpolation);
	fractol->double_params[3] = interpolate(im, fractol->double_params[3], interpolation);
	fractol->double_params[4] = (fractol->double_params[1] - fractol->double_params[0]) / (fractol->int_params[1] - 1);
	fractol->double_params[5] = (fractol->double_params[3] - fractol->double_params[2]) / (fractol->int_params[2] - 1);
	run_cl(fractol);
}
