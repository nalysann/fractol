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

	(void)x;
	(void)y;
	fractol = (t_fractol *)param;
	if (button == BUT_UP || button == BUT_DOWN)
	{
		zoom(button, x, y, fractol);
	}
	return (0);
}

int		button_release(int button, int x, int y, void *param)
{
	(void)button;
	(void)x;
	(void)y;
	(void)param;
	return (0);
}

int		motion_notify(int x, int y, void *param)
{
	t_fractol	*fractol;

	(void)x;
	(void)y;
	fractol = (t_fractol *)param;
	if (!fractol->is_fixed &&
		0 <= x && x < fractol->int_params[1] &&
		0 <= y && y < fractol->int_params[2])
	{
		fractol->double_params[6] =
				4 * ((double)x / fractol->int_params[1] - 0.5);
		fractol->double_params[7] =
				4 * ((double)(fractol->int_params[2] - y) /
								fractol->int_params[2] - 0.5);
		run_cl(fractol);
	}
	return (0);
}
