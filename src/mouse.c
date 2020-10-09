/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 14:35:59 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/14 14:36:00 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_funs.h"
#include "fractol.h"
#include "mouse.h"

int		button_press(int button, int x, int y, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (button == BUT_UP || button == BUT_DOWN)
	{
		zoom(button, x, y, fractol);
	}
	return (0);
}

int		motion_notify(int x, int y, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (!fractol->is_fixed &&
		0 <= x && x < fractol->sizex &&
		0 <= y && y < fractol->sizey)
	{
		fractol->data.param_re =
			x * fractol->data.scale + fractol->data.shift_re;
		fractol->data.param_im =
			(fractol->sizey - y) * fractol->data.scale + fractol->data.shift_im;
		run_cl(fractol);
	}
	return (0);
}
